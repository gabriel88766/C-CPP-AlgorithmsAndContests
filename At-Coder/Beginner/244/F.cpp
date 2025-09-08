#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[1 << 17][17];
vector<int> adj[17];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 63, sizeof(dp));
    queue<pair<int, int>> qp;
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        dp[1 << i][i] = 1;
        qp.push({1 << i, i});
    }
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while(qp.size()){
        auto [msk, u] = qp.front();
        qp.pop();
        for(auto v : adj[u]){
            int nmsk = msk ^ (1 << v);
            if(dp[nmsk][v] > dp[msk][u] + 1){
                dp[nmsk][v] = dp[msk][u] + 1;
                qp.push({nmsk, v});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<(1 << n);i++){
        int cm = INF_INT;
        for(int j=0;j<n;j++){
            cm = min(cm, dp[i][j]);
        }
        ans += cm;
    }
    cout << ans << "\n";
}
