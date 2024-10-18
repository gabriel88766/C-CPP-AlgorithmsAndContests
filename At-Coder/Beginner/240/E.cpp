#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int l[N], r[N];
vector<int> adj[N];
vector<int> lf;
void dfs_1(int u, int p){
    bool lff = true;
    for(auto v : adj[u]){
        if(v != p){
            lff = false;
            dfs_1(v, u);
        }
    }
    if(lff) lf.push_back(u);
}
void dfs(int u, int p){
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            l[u] = min(l[u], l[v]);
            r[u] = max(r[u], r[v]);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++) l[i] = INF_INT;
    dfs_1(1, 0);
    int cur = 0;
    for(auto x : lf){
        l[x] = r[x] = ++cur;
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++){
        cout << l[i] << " " << r[i] << "\n";
    }
}
