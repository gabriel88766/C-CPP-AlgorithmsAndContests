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
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(auto x : a){
        auto it = lower_bound(b.begin(), b.end(), x);
        ll y = it - b.begin(); //quantity of b's lower than x
        ans += y * x;
        ans -= (m - y) * x;
        ans %= MOD; 
    }
    for(auto x : b){
        auto it = upper_bound(a.begin(), a.end(), x);
        ll y = it - a.begin(); //quantity of a's lower than or equal to x
        ans += y * x;
        ans -= (n - y) * x;
        ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}
