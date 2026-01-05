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
        vector<pair<int, int>> cv(n+1);
        vector<bool> vis(n+1);
        set<pair<int, int>> st;
        for(int i=1;i<=n;i++){
            cin >> cv[i].first >> cv[i].second;
            st.insert({cv[i].first, i});
        }
        ll ans = 0;
        while(st.size()){
            auto [a, i] = *prev(st.end());
            vis[i] = true;
            st.erase(prev(st.end()));
            ans += a;
            if(i-1 >= 1 && vis[i-1] == false && cv[i-1].first + cv[i-1].second < a){
                int dif = a - cv[i-1].second - cv[i-1].first;
                st.erase({cv[i-1].first, i-1});
                cv[i-1].first += dif;
                st.insert({cv[i-1].first, i-1});
            }
            if(i+1 <= n && vis[i+1] == false && cv[i+1].first + cv[i+1].second < a){
                int dif = a - cv[i+1].first - cv[i+1].second;
                st.erase({cv[i+1].first, i+1});
                cv[i+1].first += dif;
                st.insert({cv[i+1].first, i+1});
            }
        }
        cout << ans << "\n";

    }
}
