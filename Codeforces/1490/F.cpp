#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        vector<pair<int,int>> vp;
        for(auto [k, v] : mp){
            vp.push_back({v, k});
        }
        sort(vp.begin(), vp.end());
        ll sum = 0;
        ll ans = INF_LL;
        ll cur = vp.size();
        for(auto x: vp){
            ll qt = x.first;
            ans = min(ans, n-qt*cur);
            cur--;
        }
        cout << ans << "\n";
    }
}
