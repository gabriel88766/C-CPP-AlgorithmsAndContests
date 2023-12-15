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
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<int> a(n);
        vector<ll> ans(n);
        map<int, vector<int>> mp;
        ordered_set<int> os;
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            os.insert(i);
            cin >> a[i];
            vp[i] = {a[i], i};
            mp[a[i]].push_back(i);
        }
        sort(vp.begin(), vp.end());
        int rnd = 0;
        ll beg = 0, qnt = 0;
        for(ll i=0;i<n;i++){
            if((vp[i].first-1) > rnd){
                //remove all with vp[i].first == rnd + 1;
                if(mp.count(rnd+1)){
                    for(auto x : mp[rnd+1]) os.erase(x);
                }
                ll dif = vp[i].first - 1 - rnd;
                beg += dif * (n - i) + qnt;
                rnd = vp[i].first - 1;
                qnt = 0;
            }
            qnt++;
            //cout << vp[i].second << " " << beg << "\n";
            ans[vp[i].second] = beg + os.order_of_key(vp[i].second) + 1;
        }
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
