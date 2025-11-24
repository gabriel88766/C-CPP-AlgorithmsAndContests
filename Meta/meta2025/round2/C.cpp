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
    freopen("designing_paths_input.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n, k, m;
        cin >> n >> k >> m;
        vector<vector<int>> rts(m);
        vector<set<int>> vs(m);
        vector<vector<pair<int, int>>> plc(n+1);
        vector<ll> d(n+1, INF_INT);
        d[1] = 0;
        for(int j = 0;j < m; j++){
            int sz;
            cin >> sz;
            rts[j].resize(sz);
            for(int u = 0; u < sz; u++){
                cin >> rts[j][u];
                if(rts[j][u] != 1) vs[j].insert(u); //u isn't removed yet;
                plc[rts[j][u]].push_back({j, u});
            }
        }
        //Now need to do the BFS... be smart. visit once.
        queue<int> q;
        q.push(1);
        while(q.size()){
            auto v = q.front();
            q.pop();
            for(auto [j, u] : plc[v]){
                auto it = vs[j].lower_bound(u);
                vector<int> rml;
                while(it != vs[j].end() && *it - u <= k){
                    rml.push_back(*it);
                    if(d[rts[j][*it]] > d[v] + 1){
                        d[rts[j][*it]] = d[v] + 1;
                        q.push(rts[j][*it]);
                    }
                    ++it;
                }
                for(auto x : rml) vs[j].erase(x);
            }
        }
        ll ans = 0;
        for(int j=1;j<=n;j++){
            if(d[j] == INF_INT) d[j] = -1;
            ans += d[j] * j;
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }
    
}
