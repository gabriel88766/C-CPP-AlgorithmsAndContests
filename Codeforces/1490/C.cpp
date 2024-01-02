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
    map<ll, bool> mp;
    ll mx = 1e12;
    for(ll i=1;i*i*i<=mx;i++){
        mp[i*i*i] = true;
    }
    while(t--){
        ll x;
        cin >> x;
        bool ok = false;
        for(ll i=1;i*i*i<=mx;i++){
            ll cb = i*i*i;
            if(cb >= x) break;
            if(mp.count(x - cb)){
                ok = true;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
