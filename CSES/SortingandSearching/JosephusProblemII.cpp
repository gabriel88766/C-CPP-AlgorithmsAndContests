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

int find_js(int n, int st, int k){
    int ans = (st + k+1) % n;
    if(!ans) ans = n;
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    ll st = 0;
    ordered_set<int> os;
    for(int i=1;i<=n;i++) os.insert(i);
    for(int i=n;i>=1;i--){
        int nxt = find_js(i, st, k);
        int ans = *os.find_by_order(nxt-1);
        cout << ans << " ";
        os.erase(ans);
        st = nxt-1;
    }
}
