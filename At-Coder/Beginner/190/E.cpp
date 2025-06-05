#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
int vt[20];
int d[20][N];
int od[20][20];
int dp[1 << 17][17];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++) cin >> vt[i];
    memset(d, 63, sizeof(d));
    for(int i=0;i<k;i++){
        queue<int> q;
        q.push(vt[i]);
        d[i][vt[i]] = 0;
        while(q.size()){
            auto u = q.front();
            q.pop();
            for(auto &v : adj[u]){
                if(d[i][v] > d[i][u] + 1){
                    d[i][v] = d[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            od[i][j] = d[i][vt[j]];
        }
    }
    memset(dp, 63, sizeof(dp));
    for(int i=0;i<k;i++) dp[1 << i][i] = 0;
    for(int i=1;i<(1 << k);i++){
        if(__builtin_popcount(i) == 1) continue;
        for(int j=0;j<k;j++){
            if(i & (1 << j)){
                for(int l=0;l<k;l++){
                    if(l == j) continue;
                    if(i & (1 << l)){
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][l] + od[l][j]);
                    }
                }
            }
        }
    }
    int ans = INF_INT;
    for(int i=0;i<k;i++) ans = min(ans, dp[(1 << k)-1][i]);
    if(ans == INF_INT) cout << -1 << "\n";
    else cout << ans+1 << "\n";
}
