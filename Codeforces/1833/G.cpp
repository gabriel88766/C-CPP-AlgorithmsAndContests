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
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> h(n+1);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
        h[0] = -1;
        function<void(int, int)> dfs = [&](int u, int p){
            h[u] = h[p] + 1;
            for(auto [v, j] : adj[u]){
                if(v != p){
                    dfs(v, u);
                }
            }
        };
        dfs(1, 0);
        priority_queue<pair<int, int>> pq;
        for(int i=1;i<=n;i++) pq.push({h[i], i});
        bool ok = true;
        vector<bool> rem(n+1, false);
        vector<int> ans;
        while(pq.size()){
            auto [hx, u] = pq.top();
            pq.pop();
            if(rem[u]) continue;
            rem[u] = true;
            int nv = -1;
            for(auto [v, j] : adj[u]){
                if(!rem[v]){
                    nv = v;
                }
            }
            if(nv == -1){
                ok = false;
                break;
            }else rem[nv] = true;
            int ov = -1;
            for(auto [nnv, j] : adj[nv]){
                if(!rem[nnv]){
                    if(ov == -1) ov = nnv;
                    else if(h[nnv] > h[ov]) ov = nnv;
                }
            }
            if(ov == -1){
                ok = false;
                break;
            }else rem[ov] = true;
            if(h[ov] < h[nv]){
                nv = ov;
            }
            for(auto [v, j] : adj[nv]){
                if(h[v] < h[nv]){
                    // cout << v << " " << nv  << "\n";
                    ans.push_back(j);
                    break;
                }
            }
        }   
        if(ok){
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else cout << "-1\n";
    }
}
