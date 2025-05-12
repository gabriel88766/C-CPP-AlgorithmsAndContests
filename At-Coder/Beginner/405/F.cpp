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

struct Segment{
    int l, r, t, i;
};
const int N = 2e5+3;
vector<Segment> vs;
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int l, r;
        cin >> l >> r;
        vs.push_back({l, r, 1, i});
    }
    cin >> q;
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        vs.push_back({l, r, 2, i});
    }
    sort(vs.begin(), vs.end(), [&](const Segment &a, const Segment &b){
        if(a.l != b.l) return a.l < b.l;
        else return a.r < b.r;
    });
    ordered_set<pair<int, int>> ms;
    for(auto &[l, r, t, i] : vs){
        while(ms.size() && ms.begin()->first < l) ms.erase(ms.begin());
        if(t == 2) ans[i] = ms.order_of_key({r, 0});
        else{
            ms.insert({r, i});
        }
    }
    sort(vs.begin(), vs.end(), [&](const Segment &a, const Segment &b){
        if(a.r != b.r) return a.r > b.r;
        else return a.l < b.l;
    });
    ms.clear();
    for(auto &[l, r, t, i] : vs){
        while(ms.size() && prev(ms.end())->first > r) ms.erase(prev(ms.end()));
        if(t == 2) ans[i] += ms.size() - ms.order_of_key({l, 0});
        else{
            ms.insert({l, i});
        }
    }
    for(int i=1;i<=q;i++){
        cout << ans[i] << "\n";
    }
}
