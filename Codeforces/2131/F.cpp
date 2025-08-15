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
    ll t;
    cin >> t;
    while(t--){
        ll n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        ll c1 = 0, c2 = 0;
        ll mid = n+2;
        vector<ll> cnt(2*mid + 1);
        auto upl = cnt, upr = cnt;
        auto ctl = cnt, ctr = cnt;
        for(auto c : s1){
            if(c == '1') c1++;
            else c2++;
            upr[mid + c1 - c2] += c1; //0-1 up to this
            ctr[mid + c1 - c2] += 1;
            upl[mid + c1 - c2 - 1] += c2;
            ctl[mid + c1 - c2 - 1] += 1;
        }
        for(ll i=1;i<cnt.size();i++){
            upr[i] += upr[i-1];
            ctr[i] += ctr[i-1];
        }
        for(ll i=cnt.size()-2;i>=0;i--){
            ctl[i] += ctl[i+1];
            upl[i] += upl[i+1];
        }
        ll ans = 0;
        c1 = 0, c2 = 0;
        for(auto c : s2){
            if(c == '1') c1++;
            else c2++;
            ans += ctl[mid + c2 - c1] * c2 + upl[mid + c2 - c1] + ctr[mid + c2 - c1] * c1 + upr[mid + c2 - c1];
        }
        cout << ans << "\n";
    }
}
