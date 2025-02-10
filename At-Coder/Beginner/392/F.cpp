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


const int N = 5e5+2;
int v[N], ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    ordered_set<int> os;
    for(int i=1;i<=n;i++) os.insert(i);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=n;i>=1;i--){
        int ord = *os.find_by_order(v[i] - 1);
        ans[ord] = i;
        os.erase(ord);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
