#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int dp[N];
int ans;
void dfs(int u, int p){
    vector<int> vc;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            vc.push_back(dp[v]);
        }
    }
    sort(vc.begin(), vc.end(), greater<int>());
    if(adj[u].size() == 1) dp[u] = -INF_INT; //root or leaf
    else{
        if(vc[0] >= 0) dp[u] = vc[0] + adj[u].size() - 2;
        else dp[u] = adj[u].size() - 2;
        int aux = dp[u] + 2;
        ans = max(ans, aux);
        if(vc.size() >= 2){
            if(vc[1] >= 0){
                aux = vc[0] + vc[1] + adj[u].size();
                ans = max(ans, aux);
            }
        }
    }
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
        ans = 1;
        dfs(1, 0);
        cout << ans << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
