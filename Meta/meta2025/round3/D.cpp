#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3, M = 20; 
vector<ll> adj[N];
ll rt = 1, anc[N][M], h[N];
ll ans[N], rans[N];
ll mi[N], p[N];
void mobius(){ //another sieve.
    for(ll i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1, mi[j] *= -1;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
}

void dfs(int u, int par){ 
    anc[u][0] = par;
    h[u] = h[par] + 1;
    for(auto x : adj[u]){
        if(x != par){
            dfs(x, u);
        }
    } 
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
    if(a == b) return diff;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i], diff += 2 * (1 << i);
    }
    return diff + 2;
}

ll cans = 0;
int ccc;
ll sum[N];
ll sz[N];
void dfs2(int u, int p){
    for(auto v : adj[u]){
        if(v != p){
            dfs2(v, u);
        }
    }
    if(u % ccc == 0){
        sum[u] += h[u];
        sz[u] = 1;
    }
    for(auto v : adj[u]){
        if(v != p){
            cans -= 2*h[u] * sz[v] * sz[u];
            cans += sum[v] * sz[u];
            cans += sum[u] * sz[v];
            sum[u] += sum[v];
            sz[u] += sz[v];
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("treehouse_telegram_input.txt", "r", stdin);
    // freopen("streetlamp_safety_input.txt", "r", stdin); //test input
    freopen("out2.txt", "w", stdout); //test input
    mobius();
    int t;
    cin >> t;
    const int X = 500;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        build(n);
        for(int i=1;i<=X;i++){
            for(int j=1;j<=n;j++) sum[j] = sz[j] = 0;
            cans = 0;
            ccc = i;
            dfs2(1, 0);
            ans[i] = cans;
        }
        for(int i=X+1;i<=n;i++){
            for(int j=1;j<=n/i;j++){
                for(int k=j+1;k<=n/i;k++){
                    ans[i] += lca(i*j, i*k);
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;i*j<=n;j++){
                rans[i] += ans[i*j] * mi[j];
            }
        }

        cout << "Case #" << i << ": ";
        for(int j=1;j<=n;j++) cout << rans[j] << " \n"[j==n];
        for(int i=1;i<=n;i++){
            adj[i].clear();
            ans[i] = rans[i] = 0;
        }
    }
}
