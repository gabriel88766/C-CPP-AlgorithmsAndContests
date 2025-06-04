#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    Mint pow(ll u){
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
        if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
            x = 1; y = 0;
            return a;
        }
        ll d = gcd_euclid(b, a % b, y, x); //if b > a then this step reverses it
        y -= x * (a/b); 
        return d;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    /*Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}*/
    Mint operator/= (Mint u){ //division , MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

//count number of triples such that a^b^c = d.
//need to subtract those a == b or c == d
Mint count3(int a, int b, int c, int d){
    if(a < b) swap(a, b);
    if(a < c) swap(a, c);
    if(b < c) swap(b, c);
    //a, b, c are sorted in non increasing order...
    assert(a >= b && b >= c);
    // cout << a << " " << b << " " << c << " " << d << endl;
    if(a == 0) return 1;
    int msb = 31 - __builtin_clz(max(a, d));
    int bit = 1 << msb;
    Mint ans = 0;
    if(d & bit){
        int xx;
        if(c >= bit){
            //0, 1, 2, 3
            xx = 3;
        }else if(b >= bit){
            //0, 1, 2
            xx = 2;
        }else if(a >= bit){
            //0, 1
            xx = 1;
        }else xx = 0;
        ans += Mint(min(bit, a+1)) * Mint(min(bit, b+1)) * Mint(min(bit, c+1));

        //choose 1
        if(xx >= 1){
            if(xx == 1){
                ans += count3(a-bit, b, c, d-bit);
            }else{
                if(xx >= 2){
                    ans += Mint(a - bit + 1) * Mint(min(c+1, bit)) * Mint(d+1-bit);
                    ans += Mint(b - bit + 1) * Mint(min(c+1, bit)) * Mint(d+1-bit);
                }
                if(xx >= 3) ans += Mint(c - bit + 1) * Mint(bit) * Mint(d+1-bit);
            }
        }
        //choose 2
        if(xx >= 2){
            ans += Mint(a-bit+1) * Mint(b-bit+1) * Mint(min(c+1, bit));
            if(xx > 2){
                ans += Mint(a-bit+1) * Mint(c-bit+1) * Mint(bit);
                ans += Mint(b-bit+1) * Mint(c-bit+1) * Mint(bit);
            }
        }
        //choose 3
        if(xx == 3){
            ans += count3(a-bit,b-bit,c-bit,d-bit);
        }
    }else{
        if(c & bit){
            //either choose 2 or 0
            //choose 0: C and B are any less than bit, A has D+1 possible values
            ans += Mint(bit) * Mint(bit) * Mint(d+1);
            //choose 2 (among 3):
            ans += (Mint(a-bit+1) * Mint(c-bit+1) + Mint(a-bit+1)*Mint(b-bit+1) + Mint(b-bit+1) * Mint(c-bit+1))* Mint(d+1);
        }else if(b & bit){
            //either choose 2 or 0
            //choose 0: C is any, B is any less than bit, A has D+1 possible values
            ans += Mint(c+1) * Mint(bit) * Mint(d+1);
            //choose 2:
            ans += count3(a - bit, b - bit, c, d);
        }else{
            //choose 0;
            ans += count3(bit - 1, b, c, d);
        }
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, m, A, B;
        cin >> n >> m >> A >> B;
        //a^c = b^d => a^b^c^d = 0
        //count triples a^b^c <= D and subtract triples a == b 
        Mint ans = count3(A, A, B, B) - Mint(A+1) * Mint(B+1);
        ans *= (Mint(2).pow(n-1) - 1);
        ans *= (Mint(2).pow(m-1) - 1);
        ans += Mint(A+1) * (Mint(2).pow(m-1) - 1) * Mint(B + 1) * Mint(B); 
        ans += Mint(B+1) * (Mint(2).pow(n-1) - 1) * Mint(A+1) * Mint(A);
        ans += Mint(A+1) * Mint(B+1);
        cout << ans << "\n";
    }
}
