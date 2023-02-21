#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int N = 2e5+6;
int v[N];

ordered_set<pair<int,int>> st;


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        st.insert({v[i], i});
    }
    for(int i=0;i<q;i++){
        int a,b;
        char c;
        cin >> c >> a >> b;
        if(c == '?'){
            int k1 = st.order_of_key({a, 0});
            int k2 = st.order_of_key({b+1, 0});
            cout << k2 - k1 << "\n";
        }else{
            st.erase({v[a], a});
            v[a] = b;
            st.insert({v[a], a});
        }   
    }
}
