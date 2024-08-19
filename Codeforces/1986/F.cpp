#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sum_n(ll n){
    ll ans = n * (n-1);
    ans /= 2;
    return ans;
}


const int N = 1e5+3;
vector<int> adj[N];
int in[N], low[N], sub[N], cnt = 0;
int gs = 0;
int n;

void dfs_bridge(int u, int p = -1){
    low[u] = in[u] = ++cnt;
    sub[u] = 1;
    for(auto v: adj[u]){
        if(v == p) continue;
        if(!in[v]){
            dfs_bridge(v, u);
            sub[u] += sub[v];
            if(low[v] == in[v]){
                if(sub[v] <= n/2) gs = max(gs, sub[v]);
                else gs = max(gs, n - sub[v]);
            }
        }
        low[u] = min(low[u], low[v]);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs_bridge(1);
        cout << sum_n(gs) + sum_n(n-gs) << "\n";

        for(int i=1;i<=n;i++){
            low[i] = in[i] = sub[i] = 0;
            adj[i].clear();
        }
        gs = cnt = 0;
    }
}
