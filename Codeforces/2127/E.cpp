#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n, k;
const int N = 2e5+3;
vector<int> adj[N];
ll w[N], ans = 0;
int c[N];

vector<int> ns[N];
map<int, bool> mp[N];

void dfs(int u, int p){
    bool ok = true;
    int nv = (c[u] ? c[u] : -1);
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            if(mp[v].size() > mp[u].size()){
                mp[u].swap(mp[v]);
                ns[u].swap(ns[v]);
            }
            for(auto x : ns[v]) ns[u].push_back(x);
            for(auto [k, v] : mp[v]){
                if(mp[u].count(k)){
                    if(nv == -1 || nv == k) nv = k;
                    else{
                        ok = false;
                    }
                }
                mp[u][k] = true;
            }
        }
    }
    if(c[u] == 0){
        ns[u].push_back(u);
    }else{
        mp[u][c[u]] = true;
    }
    if(nv != -1){
        for(auto x : ns[u]) c[x] = nv;
        ns[u].clear();
    }
    if(!ok) ans += w[u];
    
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> w[i];
        for(int i=1;i<=n;i++) cin >> c[i];
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ans = 0;
        dfs(1, 0);
        if(ns[1].size()){
            for(auto x : ns[1]) c[x] = 1;
        }
        cout << ans << "\n";
        for(int i=1;i<=n;i++) cout << c[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++){
            adj[i].clear();
            ns[i].clear();
            mp[i].clear();
        }
    }
}
