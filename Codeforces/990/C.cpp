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


const int N = 3e5+1;
string s[N];
int mn[N], lt[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    map<int, ordered_set<pair<int,int>>> mp;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        int cur = 0;
        for(int j=0;j<s[i].size();j++){
            if(s[i][j] == '(') cur++;
            else cur--;
            mn[i] = min(mn[i], cur);
        }
        lt[i] = cur;
        mp[lt[i]].insert({mn[i], i});
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        //concat s[i] s[j]
        if(mn[i] < 0) continue;
        //mn[j] >= -lt[i]
        //lt[i] + lt[j] = 0
        if(mp.count(-lt[i])){
            int x = mp[-lt[i]].order_of_key({-lt[i], 0});
            ans += mp[-lt[i]].size() - x;
        }
    }
    cout << ans << "\n";
}
