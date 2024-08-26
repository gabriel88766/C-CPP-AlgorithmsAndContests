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
        ll n, m;
        cin >> n >> m;
        vector<ll> m1(n, -1), m2(n, -1);
        ll mv = 0, mv2 = 0;
        int ind;
        for(int i=0;i<n;i++){
            int sz;
            cin >> sz;
            vector<ll> cur(sz);
            for(int i=0;i<sz;i++){
                cin >> cur[i];
            }
            sort(cur.begin(), cur.end());
            cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
            int p = 0;
            for(int j=0;;j++){
                if(p >= cur.size() || cur[p] != j){
                    if(m1[i] == -1) m1[i] = j;
                    else{
                        m2[i] = j;
                        break;
                    }
                }else p++;
            }
            if(m2[i] > mv){
                mv = m2[i];
                ind = m1[i];
            }
            mv2 = max(m1[i], mv2);
        }
        vector<int> cnt(mv+1, 0);
        for(int i=0;i<n;i++) cnt[m1[i]]++;
        vector<vector<int>> adj(mv+1);
        for(int i=0;i<n;i++) adj[m2[i]].push_back(m1[i]);
        vector<int> vis(mv+1, false), ansv(mv+1, mv2);
        int ch;
        function<bool(int)> dfs = [&](int u){
            ansv[u] = ch;
            vis[u] = true;
            bool ok = false;
            if(cnt[u] >= 2) ok = true;
            for(auto v : adj[u]){
                if(!vis[v]){
                    ok |= dfs(v);
                }
            }
            return ok;
        };
        ll ans = 0;
        if(m > mv){
            ans += ((m + mv + 1) * (m - mv))/2;
        }
        //now graph, for i = 0 to mv reachability
        for(int i=mv;i>=0;i--){
            if(i <= mv2) break;
            if(!vis[i]){
                ch = i;
                if(dfs(i)){
                    for(int j=0;j<=mv;j++){
                        vis[j] = true;
                        ansv[j] = max(ansv[j], ch);
                    }
                }
            }
        }
        for(int i=0;i<=min(m, mv);i++) ans += ansv[i];
        cout << ans << "\n";
    }
}
