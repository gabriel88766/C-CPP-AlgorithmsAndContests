#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;
ll sub[N], h[N];
ll tt[N];
int anc[N][M];
vector<int> adj[N];
void dfs(int u, int p){
    anc[u][0] = p;
    h[u] = h[p] + 1;
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}

void build(int n){
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
    //freopen("in"  , "r", stdin); //test input
    ll n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        ++a, ++b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    h[0] = -1;
    dfs(1, 0);
    build(n);
    ll aux = 1;
    for(auto v : adj[1]){
        tt[1] += aux * sub[v];
        aux += sub[v];
    }
    int l, r = -1;
    ll an = 0;
    for(int i=2;i<=n;i++){
        if(i == 2){
            l = 2;
            for(auto v : adj[1]){
                if(lca(v, l) == 1) an += sub[v];
            }
            an += 1;
            tt[2] = an * sub[2];
        }else{
            if(r == -1){
                int lc = lca(l, i);
                if(lc == i){
                    tt[i] = an * sub[l];
                }else if(lc == l){
                    l = i;
                    tt[i] = an * sub[l];
                }else{
                    //check if I can use i
                    bool ok = true;
                    for(auto v : adj[1]){
                        int lc1 = lca(v, i);
                        if(lc1 == v){
                            int lc2 = lca(l, v);
                            if(lc2 == v){
                                ok = false;
                            }
                        }
                    }
                    if(!ok) break;
                    r = i;
                    tt[i] = sub[l] * sub[r];
                }
            }else{
                int lc1 = lca(l, i);
                int lc2 = lca(r, i);
                if(lc1 == l || lc1 == i){
                    if(lc1 == l) l = i;
                }else if(lc2 == r || lc2 == i){
                    if(lc2 == r) r = i;
                }else break;
                tt[i] = sub[l] * sub[r];
            }
        }
    }
    ll ans = 1; //0->0
    for(int i=1;i<=n;i++){
        // cout << tt[i] << " ";
        ans += i * (tt[i] - tt[i+1]);
    }
    // cout << "\n";
    cout << ans << "\n";

}
