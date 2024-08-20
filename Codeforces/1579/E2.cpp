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
        ordered_set<pair<int,int>> os;
        int n;
        cin >> n;
        vector<int> v(n+1);
        ll ans = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            os.insert({v[i], i});
        }
        for(int i=n;i>=1;i--){
            os.erase({v[i], i});
            //find #greater and #lower;
            int low = os.order_of_key({v[i], -INF_INT});
            int hi = os.size() - os.order_of_key({v[i], INF_INT});
            ans += min(low, hi);
        }


        cout << ans << "\n";
    }

}
