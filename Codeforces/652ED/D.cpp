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
    int n;
    cin >> n;
    vector<tuple<int,int,int>> ps(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int l, r;
        cin >> l >> r;
        ps[i] = {l, r, i};
    }
    sort(ps.begin(), ps.end(), [&](tuple<int,int,int> a, tuple<int,int,int> b){
        auto [l1, r1, i1] = a;
        auto [l2, r2, i2] = b;
        assert(r1 != r2);
        if(r1 != r2) return r1 < r2;
        else return l1 > l2;
    });
    ordered_set<int> os;
    for(auto [l, r, i] : ps){
        ans[i] = os.order_of_key(r+1) - os.order_of_key(l);
        os.insert(l);
    }
    for(auto x : ans) cout << x << "\n";
}
