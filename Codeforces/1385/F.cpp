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
        int n, k;
        cin >> n >> k;
        vector<set<int>> adj(n+1);
        vector<vector<int>> ctl(n+1);
        set<int> st;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        if(k == 1){
            cout << n-1 << "\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size() == 1){
                ctl[*adj[i].begin()].push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(ctl[i].size() >= k){
                st.insert(i);
            }
        }
        int ans = 0;
        while(st.size()){
            int p = *st.begin();
            st.erase(st.begin());
            int val = ctl[p].size();
            int qt = val/k;
            ans += qt;
            for(int i=0;i<k*qt;i++){
                auto v = ctl[p].back();
                ctl[p].pop_back();
                adj[p].erase(v);
                adj[v].erase(p);
            }
            if(adj[p].size() == 1){
                ctl[*adj[p].begin()].push_back(p);
                if(ctl[*adj[p].begin()].size() == k){
                    st.insert(*adj[p].begin());
                }
            }
            

        }
        cout << ans << "\n";

    }
}
