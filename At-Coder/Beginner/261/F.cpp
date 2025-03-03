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


const int N = 3e5+3;
int c[N], v[N];
ordered_set<int> ac[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int, int>> vod;
    for(int i=1;i<=n;i++){
        cin >> c[i];
        ac[c[i]].insert(i);
    }
    for(int i=1;i<=n;i++){
        cin >> v[i];
        vod.push_back({v[i], i});
    }
    sort(vod.begin(), vod.end(), greater<pair<int,int>>());
    ll ans = 0;
    ordered_set<int> rem;
    for(auto &[xx, i] : vod){
        //check in [i, n]
        int cur = n - i + 1;
        cur -= ac[c[i]].size() - ac[c[i]].order_of_key(i);
        cur -= rem.size() - rem.order_of_key(i);
        // cout << cur << "\n";
        ans += cur;
        ac[c[i]].erase(i);
        rem.insert(i);
    }
    cout << ans << "\n";
}
