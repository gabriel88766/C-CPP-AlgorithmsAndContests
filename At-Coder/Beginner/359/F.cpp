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
    cin >> n;
    ll ans = 0;
    multiset<pair<ll, ll>> ms;
    for(int i=1;i<=n;i++){
        ll x;
        cin >> x;
        ms.insert({3*x, 3});
        ans += x;
    }
    // n, missing n-2;
    for(int i=0;i<n-2;i++){
        auto [val, qt] = *ms.begin();
        ans += val;
        ll nv = (val/qt)*(qt+2);
        ms.erase(ms.begin());
        ms.insert({nv, qt+2});
    }
    cout << ans << "\n";
}
