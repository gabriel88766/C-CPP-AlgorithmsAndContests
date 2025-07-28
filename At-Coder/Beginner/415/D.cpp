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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vp(m);
    for(int i=0;i<m;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end());
    vector<ll> mn(m);
    for(int i=0;i<m;i++){
        mn[i] = vp[i].first - vp[i].second;
        if(i != 0) mn[i] = min(mn[i], mn[i-1]);
    }
    ll ans = 0;
    for(int i=m-1;i>=0;i--){
        if(n >= vp[i].first){
            ll act = 1 + (n - vp[i].first) / mn[i];
            assert(n - act * mn[i] < vp[i].first && n >= 0);
            ans += act;
            n -= act * mn[i];
        }
    }
    cout << ans << "\n";
}
