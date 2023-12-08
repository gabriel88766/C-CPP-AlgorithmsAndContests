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


ordered_set<pair<int,int>> os;
int query(int l, int r){ //between l and r inclusive
    return os.order_of_key({r+1, 0}) - os.order_of_key({l, 0});
}

void insert(int x){
    auto it = os.lower_bound({x+1, 0});
    if(it == os.begin()) os.insert({x, 1});
    else{
        it = prev(it);
        if(it->first == x) os.insert({x, it->second+1});
        else os.insert({x, 1});
    }
}

void remove(int x){
    auto it = prev(os.lower_bound({x+1, 0}));
    os.erase(it);
}

const int MAXINT = (1 << 27) - 1;
int query2(int p, int ld, int l = 0, int r = MAXINT){
    if(l > ld) return 0;
    if(r <= ld){
        int xx = p^l;
        int len = r - l + 1;
        int beg = (xx / len) * len;
        return query(beg, beg + len - 1);
    }
    int m = (l+r)/2;
    return query2(p, ld, l, m) + query2(p, ld, m+1, r);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            insert(x);
        }else if(t == 2){
            int x;
            cin >> x;
            remove(x);
        }else{
            int p, x;
            cin >> p >> x;
            cout << query2(p, x-1) << "\n";
        }
    }
}   
