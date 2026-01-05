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
    Mint(ll u){ 
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

const int N = 5005;
vector<int> adj[N];
Mint dp[N][N];
bool hadj[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            if(a > b) swap(a, b);
            adj[a].push_back(b);
            hadj[a][b] = true;
        }
        for(int i=1;i<=n;i++){
            sort(adj[i].begin(), adj[i].end());
        }
        for(int l=n;l>=1;l--){
            //first leaf.
            dp[l][l] = 1;
            //non leaf;
            for(auto v : adj[l]){
                Mint aux = 1;
                for(int r = v; r <= n; r++){
                    if(hadj[l][r] && r != v) aux *= 2;
                    dp[l][r] += dp[l][v-1] * dp[v][r] * aux; 
                }
            }
        }

        cout << dp[1][n] << "\n";

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = 0;
                hadj[i][j] = false;
            }
        }
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }
}
