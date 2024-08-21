#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 


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
        vector<int> v(n+1), p(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i++) cin >> p[i];
        ordered_set<pair<int,int>> os;
        for(int i=1;i<=n;i++){
            os.insert({v[i], i});
        }
        ll ans = 0, qt = 0;
        for(int k=1;k<=(n+1)/2;k++){
            int ord = os.size() - 1; // 3-1
            ord -= (k-1);
            assert(ord >= 0);
            ll cur = os.find_by_order(ord)->first;
            cur *= k;
            if(cur > ans){
                ans = cur;
                qt = k;
            }
            os.erase({v[p[k]], p[k]});
        }
        cout << ans << " " << qt << "\n";
    }
}
