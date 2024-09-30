#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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
        vector<vector<int>> adj(n+1);
        vector<int> h(n+1), hh(n+1);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        h[0] = -1;
        function<void(int, int)> dfs = [&](int u,int p){
            h[u] = h[p] + 1;
            hh[u] = h[u];
            for(auto v : adj[u]){
                if(v != p){
                    dfs(v, u);
                    hh[u] = max(hh[u], hh[v]);
                }
            }
        };
        dfs(1, 0);
        vector<pair<int,int>> vp;
        for(int i=1;i<=n;i++) vp.push_back({h[i], i});
        sort(vp.begin(), vp.end());
        set<pair<int,int>> s;
        int pc = 0;
        int ans = n;
        for(int i=0;i<=n;i++){
            while(pc < n && vp[pc].first == i){
                auto [hv, j] = vp[pc];
                s.insert({hh[j], j});
                pc++;
            }
            
            while(s.size() && s.begin()->first < i){
                s.erase(s.begin());
            }
            ans = min(ans, n - (int)s.size());
        }
        cout << ans << "\n";
    }
}
