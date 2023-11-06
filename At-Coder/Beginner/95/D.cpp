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
    int n;
    ll C;
    cin >> n >> C;
    //assert(n <= 100);
    vector<ll> v(n+1), c(n+1);
    for(int i=1;i<=n;i++) cin >> v[i] >> c[i];
    ll ans = 0;
    vector<pair<ll,ll>> vp1(n+1), vp2(n+1);
    ll cur = 0;
    for(int i=1;i<=n;i++){
        cur += c[i]; 
        vp1[i] = {cur-2*v[i], (ll)i};
    }
    cur = 0;
    for(int i=n;i>=1;i--){
        cur += c[i];
        vp2[i] = {cur-2*(C-v[i]), (ll)i};
    }
    //case 1:
    cur = 0;
    set<pair<ll,ll>> s;
    s.insert({0LL, 0LL});
    for(int i=1;i<=n;i++) s.insert(vp1[i]);
    for(int i=n;i>=1;i--){
        cur += c[i];
        auto it = prev(s.end());
        while(it->second >= i){
            s.erase(it);
            it = prev(s.end());
        }
        ans = max(ans, cur + it->first - (C-v[i]));
    }
    s.clear();
    for(int i=1;i<=n;i++) s.insert(vp2[i]);
    s.insert({0, n+1});
    cur = 0;
    for(int i=1;i<=n;i++){
        cur += c[i];
        auto it = prev(s.end());
        while(it->second <= i){
            s.erase(it);
            it = prev(s.end());
        }
        ans = max(ans, cur + it->first - v[i]);
    }
    cout << ans << "\n";

}
