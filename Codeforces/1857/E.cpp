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
        ll n;
        cin >> n;
        vector<pair<ll,ll>> vp(n);
        for(ll i=0;i<n;i++){
            cin >> vp[i].first;
            vp[i].second = i; 
        }
        sort(vp.begin(), vp.end());
        ll S = 0;
        for(ll i=1;i<n;i++){
            S += vp[i].first - vp[0].first;
        }
        vector<ll> ans(n);
        ans[vp[0].second] = S + n;
        for(ll i=1;i<n;i++){
            S += (vp[i].first - vp[i-1].first)*(2*i-n);
            ans[vp[i].second] = S+n;
        }
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
