#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll ps = 0;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    map<ll, ll> mp;
    mp[0]++;
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        ps += x;
        if(mp.count(ps - k)) ans += mp[ps - k];
        mp[ps]++;
    }
    cout << ans << "\n";
}
