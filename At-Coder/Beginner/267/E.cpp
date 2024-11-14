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
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 0;
    set<pair<ll, ll>> st;
    vector<ll> val(n+1);
    vector<bool> in(n+1, true);
    for(int i=1;i<=n;i++){
        for(auto x : adj[i]){
            val[i] += v[x];
        }
        st.insert({val[i], i});
    }
    while(st.size()){
        ans = max(ans, st.begin()->first);
        int u = st.begin()->second;
        st.erase(st.begin());
        for(auto x : adj[u]){
            if(!in[x]) continue;
            assert(st.count({val[x], x}));
            st.erase({val[x], x});
            val[x] -= v[u];
            st.insert({val[x], x});
        }
        in[u] = false;
    }
    
    cout << ans << "\n";
}
