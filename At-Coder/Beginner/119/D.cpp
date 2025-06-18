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
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> va(a), vb(b);
    for(int i=0;i<a;i++) cin >> va[i];
    for(int i=0;i<b;i++) cin >> vb[i];
    for(int i=0;i<q;i++){
        ll x;
        cin >> x;
        auto it1 = lower_bound(va.begin(), va.end(), x);
        auto it2 = lower_bound(vb.begin(), vb.end(), x);
        ll l1, l2, r1, r2;
        if(it1 != va.begin()) l1 = x - *prev(it1);
        else l1 = 1e16;
        if(it1 != va.end()) r1 = *it1 - x;
        else r1 = 1e16;
        if(it2 != vb.begin()) l2 = x  - *prev(it2);
        else l2 = 1e16;
        if(it2 != vb.end()) r2 = *it2 - x;
        else r2 = 1e16;
        ll ans = min({max(l1, l2), max(r1, r2), l1 + r2 + min(l1, r2), l2 + r1 + min(l2, r1)});
        cout << ans << "\n";
    }
}
