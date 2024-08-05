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
    map<int, ordered_set<int>> mp;
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mp[x].insert(i);
        v[i] = x;
    }
    for(int i=0;i<q;i++){
        int t, l, r, x;
        cin >> t >> l >> r;
        if(t == 0){
            mp[v[l]].erase(l);
            v[l] = r;
            mp[v[l]].insert(l);
        }else{
            cin >> x;
            if(mp.count(x)) cout << mp[x].order_of_key(r) - mp[x].order_of_key(l) << "\n";
            else cout << "0\n";
        }
    }
}
