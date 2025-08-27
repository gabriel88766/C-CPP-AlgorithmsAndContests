#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
vector<int> adj[N];
int dfs(int u, int p){
    int ret = 0;
    if(p == 0){
        for(auto v : adj[u]) ret += dfs(v, u);
        return ret;
    }
    int cnt = 0;
    for(auto v : adj[u]){
        if(v != p){
            int x = dfs(v, u);
            if(x == 0) cnt++;
            else ret += x;
        }
    }
    if(cnt > 1) ret += cnt - 1;
    return ret;
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
        if(n == 1) cout << "0\n";
        else {
            int ans = INF_INT;
            for(int i=1;i<=n;i++){
                if(adj[i].size() == 1){
                    ans = min(ans, dfs(i, 0) + 1);
                }
            }
            cout << ans << "\n";
        }

        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
