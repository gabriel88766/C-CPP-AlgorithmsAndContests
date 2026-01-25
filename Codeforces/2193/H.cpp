#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int val[N], h[N];
bool vis[N];
vector<int> adj[N];
void dfs(int u, int p){
    h[u] = h[p] + 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
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
        for(int i=1;i<=n;i++){
            cin >> val[i];
            val[i] %= 2;
        }
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        h[0] = -1;
        dfs(1, 0);
        set<pair<int, int>> s;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            int sum = 0;
            for(auto v : adj[i]) sum ^= val[v];
            if(sum != val[i]){
                if(val[i] == 0){
                    ans.push_back(i);
                    vis[i] = true;
                }else s.insert({h[i], i});
            }
        }
        while(s.size()){
            auto [hx, u] = *prev(s.end());
            s.erase(prev(s.end()));
            ans.push_back(u);
            vis[ans.back()] = true;
            for(auto v : adj[u]){
                if(val[v] == 0){
                    if(!vis[v]){
                        vis[v] = true;
                        ans.push_back(v);
                    }
                    continue;   
                }
                if(vis[v] == false){
                    if(s.count({h[v], v})) s.erase({h[v], v});
                    else s.insert({h[v], v});
                }
            }
        }

        if(ans.size() == n){
            cout << "YES\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else{
            cout << "NO\n";
        }


        for(int i=1;i<=n;i++){
            adj[i].clear();
            vis[i] = false;
        }
    }
}
