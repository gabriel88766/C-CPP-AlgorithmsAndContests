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
    ordered_set<pair<int,int>> elements;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        elements.insert({i, aux});
    }
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        auto element = *elements.find_by_order(aux-1);
        ans[i] = element.second;
        elements.erase(element);
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}
