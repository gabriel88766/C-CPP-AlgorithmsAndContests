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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 1e4+3;
Mint dp1[N][1024][2], dp2[N][1024][2];

void calc(string &s){
    int n = s.size();
    dp1[n][0][0] = dp1[n][0][1] = 0;
    dp2[n][0][0] = dp2[n][0][1] = 1;
    Mint cp = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){ //j==0, then no restriction, j==1 then restrition.
            for(int d=0;d<=9;d++){
                int b = 1 << d;
                if(d == 0 && i == 0) b = 0;
                for(int msk=0;msk <=1023; msk++){                
                    if(j == 1){
                        if(d < s[i] - '0'){
                            dp2[i][msk | b][1] += dp2[i+1][msk][0];
                            dp1[i][msk | b][1] += dp1[i+1][msk][0] + Mint(d) * cp * dp2[i+1][msk][0];
                        }else if(d == s[i] - '0'){
                            dp2[i][msk | b][1] += dp2[i+1][msk][1];
                            dp1[i][msk | b][1] += dp1[i+1][msk][1] + Mint(d) * cp * dp2[i+1][msk][1];
                        }else break;
                    }else{
                        dp2[i][msk | b][0] += dp2[i+1][msk][0];
                        dp1[i][msk | b][0] += dp1[i+1][msk][0] + Mint(d) * cp * dp2[i+1][msk][0];
                    }
                }
            }
        }
        cp *= 10;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    vector<int> v(m);
    for(int i=0;i<m;i++) cin >> v[i];
    int sm = 0;
    for(int i=0;i<m;i++){
        sm |= (1 << v[i]);
    }
    calc(s);
    Mint ans = 0;
    for(int i=0;i<(1 << 10);i++){
        if((sm & i) == sm){
            ans += dp1[0][i][1];
            /*if(i & 1){
                ans += dp1[0][i][1];
                //for(int j=1;j<=n-1;j++) ans -= dp1[j][i^1][0];
            }else ans += dp1[0][i][1];*/
        }
    }
    cout << ans << "\n";
}
