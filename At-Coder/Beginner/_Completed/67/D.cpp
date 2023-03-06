#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int sz[N], h[N], par[N];
vector<int> adj[N];

void dfs(int u, int p = -1){
    sz[u] = 1;
    if(p != -1) h[u] = h[p] + 1;
    par[u] = p;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sz[u] += sz[v];
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
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    int maxn = n;
    for(int i=0;i<(h[n]-1)/2;i++){
        maxn = par[maxn];
    }   
    if(sz[maxn] >= (n-sz[maxn])) cout << "Snuke";
    else cout << "Fennec";
}
 