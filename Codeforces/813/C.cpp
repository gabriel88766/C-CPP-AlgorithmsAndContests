#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int h[N], lh[N], par[N];

void dfs(int u, int p){
    lh[u] = h[u] = h[p] + 1;
    par[u] = p;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            lh[u] = max(lh[u], lh[v]);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    h[0] = -1;
    int n, x;
    cin >> n >> x;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    int mv = lh[x];
    int cur = x;
    //if h = 1, cant go up. if h = 2, cant up, if h = 3, can up 1, if h = 4 can up 1, if h = 5 can up 2
    for(int i=1;i<=(h[x]-1)/2;i++){
        cur = par[cur];
        mv = max(mv, lh[cur]);
    }
    cout << 2*mv << "\n";
}
