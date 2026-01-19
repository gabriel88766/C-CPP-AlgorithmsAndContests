#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int h[N], par[N], cl[N];
void dfs(int u, int p){
    h[u] = h[p] + 1;
    par[u] = p;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
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
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        h[0] = -1;
        dfs(1, 0);
        int mx = *max_element(h, h + n + 1);
        vector<vector<int>> v(mx+1);
        for(int i=1;i<=n;i++){
            v[h[i]].push_back(i);
        }
        int ans = 1;
        cl[1] = 1;
        for(int i=1;i<=mx;i++){
            set<int> ap;
            for(auto x : v[i]) ap.insert(par[x]);
            if(ap.size() == 1) ans = max(ans, (int)(v[i].size() + 1));
            else ans = max(ans, (int)(v[i].size()));
        }
        cout << ans << "\n";

        for(int i=1;i<=n;i++){
            h[i] = par[i] = cl[i] = 0;
            adj[i].clear();
        }
    }
}
