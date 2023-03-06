#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n+1), y(m+1);
    for(ll i=1;i<=n;i++) cin >> x[i];
    for(ll j=1;j<=m;j++) cin >> y[j];
    sort(x.begin()+1, x.end());
    sort(y.begin()+1, y.end());
    ll xf = 0, yf = 0;
    for(ll i=1;i<n;i++){
        ll cur = (n - i) * i;
        cur *= (x[i+1] - x[i]);
        xf = (xf + cur) % MOD;
    }
    for(ll i=1;i<m;i++){
        ll cur = (m - i) * i;
        cur *= (y[i+1] - y[i]);
        yf = (yf + cur) % MOD;
    }
    ll ans = (xf * yf) % MOD;
    cout << ans;

}
