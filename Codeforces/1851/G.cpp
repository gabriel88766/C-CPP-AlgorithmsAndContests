#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;   
vector<int> adj[N], adjT[N];
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

int anc[N][M], h[N], v[N], val[N][M];
vector<int> rt;

void dfs(int u, int par){ 
    anc[u][0] = par;
    val[u][0] = v[par];
    h[u] = h[par] + 1;
    for(auto x : adjT[u]){
        if(x != par){
            dfs(x, u);
        }
    } 
}

void build(int n){
    h[0] = -1;
    for(auto x : rt) dfs(x, 0);
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
            val[i][j] = max(val[i][j-1], val[anc[i][j-1]][j-1]);
        }
    }
}

int lca(int a, int b){ 
    int vr = max(v[a], v[b]);
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) { vr = max(vr, val[b][i]); b = anc[b][i];}
    if(a == b) return vr;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]){ vr = max(vr, max(val[b][i], val[a][i])); a = anc[a][i], b = anc[b][i]; }
    }
    return max(vr, val[a][0]);
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
        vector<pair<int,int>> vp(n+1);
        vector<pair<int,pair<int,int>>> vkrsk;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            vp[i].first = v[i];
            vp[i].second = i;
        }
        sort(vp.begin(), vp.end());
        //ordered to join
        for(int i=1;i<=m;i++){
            int a,b;
            cin >> a >> b;
            vkrsk.push_back({max(v[a],v[b]), {a, b}});
        }
        sort(vkrsk.begin(), vkrsk.end());
        //join
        for(auto x : vkrsk){
            if(get(x.second.first) != get(x.second.second)){
                unite(x.second.first, x.second.second);
                adjT[x.second.first].push_back(x.second.second);
                adjT[x.second.second].push_back(x.second.first);
            }
        }
        //lca
        set<int> allC;
        for(int i=1;i<=n;i++){
            if(!allC.count(get(i))){
                allC.insert(get(i));
                rt.push_back(get(i));
            }
        }
        build(n);
        int q;
        cin >> q;
        for(int i=1;i<=q;i++){
            int a,b,e;
            cin >> a >> b >> e;
            if(a == b) cout << "YES\n";
            else if(get(a) != get(b)) cout << "NO\n";
            else{
                int c = lca(a, b);
                if(c-v[a] <= e) cout << "YES\n";
                else cout << "NO\n";
            }
        }
        cout << "\n";
        for(int i=0;i<=n;i++) {adj[i].clear(); adjT[i].clear(); h[i] = 0; v[i] = 0;}
        rt.clear();
    } 
}
