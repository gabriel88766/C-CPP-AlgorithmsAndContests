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
    map<ll, ll> mp;
    vector<ll> a(n+1), ps(n+1);
    ll s = 0;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ps[i] = s;
        mp[s % m]++;
        s += a[i];
    }
    for(int i=1;i<=n;i++){
        ans += mp[ps[i] % m] - 1;
        mp[ps[i] % m]--;
        mp[s % m]++;
        s += a[i];
    }
    cout << ans << "\n";
}
