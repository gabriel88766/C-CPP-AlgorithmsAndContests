#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 305;
Mint dp[N][N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    ll a, b, c, d, e, f;
    cin >> n >> m >> a >> b >> c >> d >> e >> f;
    vector<pair<ll, ll>> vp(m);
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        vp[i] = {x, y};
    }
    sort(vp.begin(), vp.end());
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;j+k<=i;k++){
                int z = i - j - k;
                ll xc = a * j + c * k + e * z;
                ll yc = b * j + d * k + f * z;
                auto it = lower_bound(vp.begin(), vp.end(), make_pair(xc, yc));
                if(it != vp.end() && *it == make_pair(xc, yc)) continue;
                dp[i][j][k] += dp[i-1][j][k];
                if(j > 0) dp[i][j][k] += dp[i-1][j-1][k];
                if(k > 0) dp[i][j][k] += dp[i-1][j][k-1];
            }
        }
    }
    Mint ans = 0;
    for(int j=0;j<=n;j++){
        for(int k=0;k+j<=n;k++){
            ans += dp[n][j][k];
        }
    }
    cout << ans << "\n";
}
