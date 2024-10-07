#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 405;
int dist[N][N], dp[N][N], odp[N][N];
int v[N];
vector<tuple<int,int,int>> qrs[N];



int opt[N][N];

void knuth(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            odp[i][j] = dp[i][j];
        }
    }
    memset(dp, 63, sizeof(dp));
    for(int i=1;i<=n;i++) opt[i][i] = i, dp[i][i] = 0;
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for(int k=opt[i][j-1]; k <= opt[i+1][j]; k++){
                if(dp[i][j] > max(odp[i][k], dist[k][j])){
                    dp[i][j] = max(odp[i][k], dist[k][j]);
                    opt[i][j] = k;
                }
            }
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[i][j] = dist[i][j] = v[j] - v[i];
        }
    }
    for(int i=0;i<m;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        qrs[d].push_back({a, b, c});
    }
    ll ans = 0;
    for(int i=0;i<=n;i++){
        for(auto [a, b, c] : qrs[i]){
            ll cur = c;
            cur *= dp[a][b];
            ans = max(ans, cur);
        }
        knuth(n);
    }
    cout << ans << "\n";
}
