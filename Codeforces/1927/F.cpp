#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;   
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

struct Edge{
    int a, b, w;
    bool operator< (Edge v){
        if(w != v.w) return w < v.w;
        else return make_pair(a, b) < make_pair(v.a, v.b);
    }
};

vector<Edge> edges;
vector<pair<int,int>> chk;
vector<int> adj[N], adjw[N];

void kruskal(int n){
    sort(edges.begin(), edges.end());
    init(n);
    for(auto e : edges){
        if(get(e.a) != get(e.b)){
            adj[e.a].push_back(e.b);
            adjw[e.a].push_back(e.w);
            adj[e.b].push_back(e.a);
            adjw[e.b].push_back(e.w);
            unite(e.a, e.b);
        }else{
            chk.push_back({e.a, e.b});
        }
    }
}



int rt = 1, anc[N][M], h[N], minv[N][M];
int vis[N];

void dfs(int u, int par){ 
    vis[u] = true;
    anc[u][0] = par;
    minv[u][0] = INF_INT;
    h[u] = h[par] + 1;
    for(int i=0;i<adj[u].size();i++){
        if(adj[u][i] != par){
            dfs(adj[u][i], u);
        }else{
            minv[u][0] = adjw[u][i];
        }
    } 
}

void build2(int n){
    h[0] = -1;
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i, 0);
    }
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
            minv[i][j] = min(minv[i][j-1], minv[anc[i][j-1]][j-1]);
        }
    }
}

int lca(int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) b = anc[b][i];
    if(a == b) return a;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}

int lcad(int a, int b){ 
    int ans = INF_INT;
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)){
        ans = min(ans, minv[b][i]);
        b = anc[b][i];
    }
    if(a == b) return ans;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]){
            ans = min(ans, minv[b][i]);
            ans = min(ans, minv[a][i]);
            a = anc[a][i], b = anc[b][i];
        }
    }
    ans = min(ans, minv[a][0]);
    ans = min(ans, minv[b][0]);
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
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n;i++) vis[i] = 0;
        for(int i=0;i<m;i++){
            int a, b, w;
            cin >> a >> b >> w;
            edges.push_back({a, b, w});
        }
        kruskal(n);
        build2(n);
        //solve
        int mind = INF_INT;
        pair<int,int> ans;
        for(auto [u, v] : chk){
            if(lcad(u, v) < mind){
                mind = lcad(u, v);
                ans = {u, v};
            }
        }
        cout << lcad(ans.first, ans.second) << " ";
        vector<int> a1, a2;
        int lc = lca(ans.first, ans.second);
        int cur = ans.first;
        while(cur != lc){
            a1.push_back(cur);
            cur = anc[cur][0];
        }
        cur = ans.second;
        while(cur != lc){
            a2.push_back(cur);
            cur = anc[cur][0];
        }
        reverse(a2.begin(), a2.end());
        a1.push_back(lc);
        for(auto x : a2) a1.push_back(x);
        cout << a1.size() << "\n";
        for(auto x : a1) cout << x << " ";
        cout << "\n";

        
        for(int i=1;i<=n;i++){
            adj[i].clear();
            adjw[i].clear();
        }
        edges.clear();
        chk.clear();
    }
}
