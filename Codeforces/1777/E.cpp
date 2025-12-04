#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}



vector<int> adj[N];
int dfs_low[N], dfs_num[N], cmpnum[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N];

void tarjan(int u){ //SCC, cmp is in inverse topological order 
    dfs_low[u] = dfs_num[u] = ++cntT;
    visc[u] = 1;
    curcmp.emplace_back(u);
    for(auto v : adj[u]){
        if(!dfs_num[v]) tarjan(v);
        if(visc[v] == 1) dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++cntCmp;
        while(true){
            int v = curcmp.back(); curcmp.pop_back(); visc[v] = 2;
            cmp[cntCmp].emplace_back(v);
            cmpnum[v] = cntCmp;
            if(v == u) break;
        }
    }
}

bool vis[N];
int cv = 0;
void dfs(int u){
    cv++;
    vis[u] = true;
    for(auto v : adj[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
        }
    }
}

void clear(int n){
    cntT = cntCmp = cv = 0;
    curcmp.clear();
    for(int i=1;i<=n;i++){
        dfs_low[i] = dfs_num[i] = cmpnum[i] = visc[i] = 0;
        vis[i] = false;
        cmp[i].clear();
        adj[i].clear();
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
        int n, m;
        cin >> n >> m;
        init(n);
        map<pair<int, int>, int> mp;
        vector<tuple<int, int, int>> dir_edge;
        vector<pair<int, int>> undir_edge;
        for(int i=1;i<=m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            if(mp.count({b, a})){
                mp.erase({b, a});
                undir_edge.push_back({a, b});
            }else{
                mp[{a, b}] = c;
            }
            unite(a, b);
        }
        for(auto [pair, w] : mp){
            dir_edge.push_back({w, pair.first, pair.second});
        }
        sort(dir_edge.begin(), dir_edge.end());
        if(sz[get(1)] == n){
            int lo = 0, hi = dir_edge.size();
            while(lo != hi){
                int mid = lo + (hi - lo)/2;
                clear(n);
                for(int i=0;i<mid;i++){
                    auto [w, a, b] = dir_edge[i];
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
                for(int i=mid;i<dir_edge.size();i++){
                    auto [w, a, b] = dir_edge[i];
                    adj[a].push_back(b);
                }
                for(int i=0;i<undir_edge.size();i++){
                    auto [a, b] = undir_edge[i];
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
                for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
                dfs(cmp[cntCmp][0]);
                if(cv == n) hi = mid;
                else lo = mid + 1;
            }
            if(lo == 0) cout << "0\n";
            else cout << get<0>(dir_edge[lo-1]) << "\n";
        }else cout << "-1\n";
    }
}
 