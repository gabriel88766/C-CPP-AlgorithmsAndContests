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

const int N = 500; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}

Mint sum[N];
//O(N log N)
Mint sumpow(ll n, ll k){
    sum[0] = 0;
    for(int i=1;i<=k+2;i++){
        sum[i] = sum[i-1] + Mint(i).pow(k);
    }
    if(n <= k+2) return sum[n];
    else{
        //https://en.wikipedia.org/wiki/Lagrange_polynomial
        // ym = sum[m], k+1 points
        Mint ans = 0;
        Mint prod = 1;
        for(int i=1;i<=k+2;i++) prod *= (n - i);
        //cout << prod << "\n";
        for(int i=1;i<=k+2;i++){
            //cout << sum[i] << " " << prod << " " << fat[k+2-i] << " " << fat[i-1] << " " << n-i << "\n";
            if((k+2-i) % 2) ans -= sum[i] * prod / (fat[k+2-i]*fat[i-1] * (n - i));
            else ans += sum[i] * prod / (fat[k+2-i]*fat[i-1] * (n - i));
            //cout << ans << "\n";
        }
        return ans;
    }
}

void print(vector<Mint> &pol){
    for(auto &x : pol) cout << x << " ";
    cout << "\n";
}
Mint res[55][55];
Mint sp[55];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    ll n, k;
    cin >> n >> k;
    int cnt = 0;
    Mint ans = 0;
    for(int i=0;i<=n+2;i++) sp[i] = sumpow(k, i);
    for(int i=0;i<=n;i++){
        for(int j=0;i+j<=n;j++){
            //res[i][j] = Sum( (m-1)^i * (k-m)^j * m) from m = 1 to k (0^0 = 1 here)
            vector<Mint> pol(n+3);
            pol[1] = 1;
            for(int u=0;u<i;u++){
                vector<Mint> npol(n+3);
                for(int u=0;u<=n+2;u++){
                    if(u != 0) npol[u] += pol[u-1];
                    npol[u] -= pol[u];
                }
                pol = npol;
            }
            for(int u=0;u<j;u++){
                vector<Mint> npol(n+3);
                for(int u=0;u<=n+2;u++){
                    if(u != 0) npol[u] -= pol[u-1];
                    npol[u] += pol[u]*k;
                }
                pol = npol;
            }
            // if(i == 0 && j == 1) print(pol);
            for(int u=0;u<=n+2;u++){
                res[i][j] += sp[u] * pol[u];
            }
            
        }
    }
    for(int i=1;i<=n;i++){
        int c = i-1;
        int d = n - i;
        for(int a=0;a<=c;a++){
            for(int b=0;b<=d;b++){
                for(int u=0;u<=c-a;u++){
                    for(int v=u+1;v<=d-b;v++){
                        Mint pd = nCr(c, a) * nCr(d, b) * nCr(c-a, u) * nCr(d-b, v);
                        int x1 = u + d-b-v; //x1 <= n
                        int x2 = v + c-a-u; //x2 <= n
                        //x1 + x2 < n
                        // ans += pd * Sum( (m-1)^x1 * (k-m)^x2 * m) from m = 1 to k (0^0 = 1 here)
                        // cout << c << " " << d << " " << a << " " << b << " " << u << " " << v << " " << x1 << " " << x2 << " : ";
                        // cout << pd << " " << res[x1][x2] << "\n";
                        ans += pd * res[x1][x2];
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
