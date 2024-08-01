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

const int N = 2e5+1;
int ans[N];

struct Query{
    int i, x, j;
    bool operator< (const Query &q) const {
        if(x != q.x) return x < q.x;
        else return i < q.i;
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<ll> lv(n+1);
    ordered_set<pair<int,int>> os;

    for(int i=1;i<=n;i++) cin >> lv[i];

    for(int i=1;i<=n;i++){
        int lo = 1, hi = n;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            int x = os.order_of_key({mid+1, 0}); 
            if(1 + x/mid > lv[i]) lo = mid + 1;
            else hi = mid;
        }
        ans[i] = lo;
        os.insert({ans[i], i});
    }





    vector<Query> vq(q);
    for(int i=0;i<q;i++){
        int j, x;
        cin >> j >> x;
        if(ans[j] <= x) cout << "YES\n";
        else cout << "NO\n";
    }

}
