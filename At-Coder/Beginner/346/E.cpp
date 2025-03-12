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

const int N = 2e5+3;
pair<int, int> rw[N], cl[N];
ll ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, m;
    cin >> h >> w >> m;
    ordered_set<pair<int,int>> ar, ac;
    ans[0] = h;
    ans[0] *= w;
    for(int i=1;i<=m;i++){
        int tc, a, x;
        cin >> tc >> a >> x;
        if(tc == 1){
            ar.erase(rw[a]);
            rw[a] = {i, x};
            ar.insert(rw[a]);
        }else{
            ac.erase(cl[a]);
            cl[a] = {i, x};
            ac.insert(cl[a]);
        }
    }
    for(auto &[i, x] : ar){
        if(x == 0) continue;
        ans[x] += w;
        ans[x] -= ac.size() - ac.order_of_key({i, 0});
    }
    for(auto &[i, x] : ac){
        if(x == 0) continue;
        ans[x] += h;
        ans[x] -= ar.size() - ar.order_of_key({i, 0});
    }
    for(int i=1;i<N;i++) ans[0] -= ans[i];
    vector<pair<ll, ll>> ra;
    for(int i=0;i<N;i++){
        if(ans[i]) ra.push_back({i, ans[i]});
    }
    cout << ra.size() << "\n";
    for(auto [a, b] : ra) cout << a << " " << b << "\n";

}
 