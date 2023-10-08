#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int color[N];
vector<int> adj[N];
int par[N];
int node_begin_cycle;

bool dfs_cycle(int u, int p){
    color[u] = 1;
    par[u] = p;
    for(auto i : adj[u]){
        if(i == p) continue; //uncomment if undirected.
        if(color[i] == 0 && dfs_cycle(i, u)) return true;
        else if(color[i] == 1){
            node_begin_cycle = i;
            par[i] = u;
            return true; 
        }
    }
    color[u] = 2;
    return false;
}
vector<int> find_cycle(int n){ //if returned vector is empty, then no cycle
    vector<int> ans;
    node_begin_cycle = -1;
    for(int i=1;i<=n;i++) color[i] = 0;
    for(int i=1;i<=n;i++) if(!color[i] && dfs_cycle(i, -1)) break;
    if(node_begin_cycle == -1) return ans;
    int s = node_begin_cycle, cur = node_begin_cycle;
    do{
        ans.push_back(cur);
        cur = par[cur];
    }while(cur != s);
    //ans.push_back(cur); 
    //reverse(ans.begin(), ans.end()); //
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        for(int i=1;i<=n;i++){
            int c, d;
            cin >> c >> d;
            adj[c].push_back(d);
            adj[d].push_back(c);
        }
        auto cycle = find_cycle(n);
        bool ok = false;
        vector<int> d1(n+1, INF_INT);
        vector<int> d2(n+1, INF_INT);
        function<void(vector<int>&,int)> bfs = [](vector<int> &d, int u){
            queue<int> q;
            q.push(u);
            d[u] = 0;
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(d[v] > d[u]+1){
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
        };
        bfs(d1, a);
        bfs(d2, b);
        for(auto x : cycle){
            if(d1[x] > d2[x]) ok = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
