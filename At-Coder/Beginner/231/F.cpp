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
template <typename T> using ordered_set =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first;
    for(int i=0;i<n;i++) cin >> v[i].second;
    sort(v.begin(), v.end());
    int p = 0;
    ordered_set<int> os;
    ll ans = 0;
    for(int i=0;i<n;i++){
        while(p < n && v[p].first == v[i].first){
            //dosome
            os.insert(v[p].second);
            p++;
        }
        int qt = os.size() - os.order_of_key(v[i].second);
        ans += qt;
    }
    cout << ans << "\n";
}
