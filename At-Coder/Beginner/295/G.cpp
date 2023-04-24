#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], val[N];
int par[N];
vector<int> ch[N];

void init(){
    for(int i=1;i<N;i++) {val[i] = p[i] = i; sz[i] = 1;}
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
    val[a] = min(val[a], val[b]);
}

const int M = 20;
int rt = 1, anc[N][M], h[N];

void dfs(int u, int par){ 
    anc[u][0] = par;
    h[u] = h[par] + 1;
    for(auto x : ch[u]) dfs(x, u);
}

void build(int n){
    h[0] = -1;
    dfs(rt, 0);
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
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
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, q;
    cin >> n;
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        par[i] = x;
        ch[x].push_back(i);
    }
    build(n);
    cin >> q;
    for(int i = 0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int a, b;
            cin >> a >> b;
            val[get(a)] = min(val[get(a)], b);

            int aux = a;
            while(val[get(aux)] > get(b)){
                unite(aux, b);
                aux = par[aux];
            }
        }else{
            int a;
            cin >> a;
            cout << val[get(a)] << "\n";
        }
    }
}
