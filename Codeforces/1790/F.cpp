//Unsolved.
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+5;
int adj[N];



const int N = 2e5+6, M = 20;
ll st[4*N], lz[4*N];
ll v[N];
int n, cntn = 0;
int real[N], child[N], p[N][M];

bool vis[N];

void dfs(int u){
    real[++cntn] = u;
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
        child[u] += child[i] + 1;
    }
}

void destroy(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = 0; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
}

ll query(int i, int j, int l = 1, int r = n, int node = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[node];
    return query(i, j, l, (l + r)/2, 2 * node) + query(i, j, (l + r)/2 + 1, r, 2 * node + 1); //some operation
}

void update(int i, int l = 1, int r = n, int node = 1){
    if(i < l || i > r) return;
    if(l ==  r) {st[node] = 1;  return;}
    update(i, j, value, l, (l + r)/2, 2 * node);
    update(i, j, value, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int c;
        cin >> n >> c;
        vector<int> cs;
        for(int i=1;i<n;i++){
            int aux;
            cin >> aux;
            cs.push_back(aux);
        }
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1);
        update(real[c]);


        for(int i=1;i<=n;i++) adj[i].clear(); 
        for(int i=1;i<=n;i++) vis[i] = false;
        destroy();
    }
}
