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
        vector<int> p(n+1), v(n+1), ans(n+1);
        vector<vector<int>> adj(n+1);
        int rt = -1;
        for(int i=1;i<=n;i++){
            cin >> p[i];
            if(i != p[i]) adj[p[i]].push_back(i);
            else rt = i;
        }
        for(int i=1;i<=n;i++) cin >> v[i]; //permutation
        set<pair<int,int>> st; //for easy remove
        st.insert({rt, 0});
        bool ok = true;
        for(int i=1;i<=n;i++){
            auto it = st.lower_bound({v[i], 0});
            if(it != st.end() && it->first == v[i]){
                auto p = *it;
                st.erase(it);
                int df = i - 1 - p.second;
                ans[v[i]] = df;
                for(auto v : adj[p.first]){
                    st.insert({v, i-1});
                }
            }else{
                ok = false;
                break;
            }
        }
        if(ok){
            for(int i=1;i<=n;i++) cout << ans[i] << " ";
            cout << "\n";
        }else cout << "-1\n";

    }
}
