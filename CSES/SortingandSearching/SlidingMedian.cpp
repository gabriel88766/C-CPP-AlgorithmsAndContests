#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ordered_set<pair<int,int>> sp;
    vector<int> ans;
   
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(i < k){
            sp.insert({v[i], i});
        }else{
            if(i > k) sp.erase({v[i-k], i-k});
            sp.insert({v[i], i});
            int num = k/2;
            if( k % 2){
                ans.push_back(sp.find_by_order(num)->first);
            }else{
                int aux = sp.find_by_order(num-1)->first;
                ans.push_back(aux);
            }
        }   
    }

    for(int i=0; i<ans.size();i++) cout << ans[i] << " ";
}
