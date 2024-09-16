#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<int> adj[N];
int dp[N];
int ans = 0;
void dfs(int u, int p = 0){
    vector<int> pv = {0, 0};
    int cnt = 0;
    for(auto v : adj[u]){
        if(v != p){
            cnt++;
            dfs(v, u);
            pv.push_back(dp[v]);
        }
    }
    sort(pv.begin(), pv.end(), greater<int>());
    // int x = adj[u].size() >= 3 ? 1 : 0;
    if(p != 0) ans = max(ans, pv[0] + pv[1] + cnt); 
    else ans = max(ans, pv[0] + pv[1] + cnt - 1);
    if(adj[u].size() > 1) dp[u] = pv[0] + cnt;
    else dp[u] = 1;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ans = 0;
        if(n == 2){
            cout << "2\n";
        }else{
            int rt = -1;
            for(int i=1;i<=n;i++){
                if(adj[i].size() != 1){
                    rt = i;
                    break;
                }
            }
            assert(rt != -1);
            dfs(rt, 0);
            cout << ans << "\n";
        }
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}