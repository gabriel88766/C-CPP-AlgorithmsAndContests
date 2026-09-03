#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int vec[N];
vector<int> adj[N];
int n;
int ans = 0;

int aux[N], p[N];
set<int> sx[N];

void dfs(int u, int par){
    bool rm = false;
    p[u] = u;
    bool lf = true;
    for(auto v : adj[u]){
        if(v != par){
            dfs(v, u);
            if(lf == true){
                lf = false;
                if(sx[p[v]].count(vec[u] ^ aux[p[v]])) rm = true;
                p[u] = p[v];
                sx[p[u]].insert(aux[p[u]]);
                aux[p[u]] ^= vec[u];
                continue;
            }
            vector<int> nv;
            for(auto x : sx[p[v]]){
                if(sx[p[u]].count(x ^ aux[p[v]] ^ aux[p[u]])){
                     rm = true;
                }
                nv.push_back(x ^ aux[p[v]] ^ aux[p[u]] ^ vec[u]);
            }            
            for(auto x : nv) sx[p[u]].insert(x);
        }
    }
    
    if(lf){
        sx[p[u]].insert(vec[u]); 
    }
    if(rm == true){
        ans++;
        sx[p[u]].clear();
    }
}

int sub[N];

void dfs1(int u, int p){
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    
    cin >> n;
    for(int i=1;i<=n;i++) cin >> vec[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 
    int rt = 1;
    dfs1(rt, 0);
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end(), [&](int a, int b){
            return sub[a] > sub[b];
        });
    }
    dfs(rt, 0);
    cout << ans << "\n";
}