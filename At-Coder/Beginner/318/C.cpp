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
    ll n, d, p;
    cin >> n >> d >> p;
    vector<ll> f(n);
    for(int i=0;i<n;i++) cin >> f[i];
    sort(f.begin(), f.end(), greater<int>());
    vector<ll> ps(n+1, 0);
    for(int i=0;i<n;i++){
        ps[i+1] = ps[i] + f[i];
    }
    ll ans = 0;
    for(int i = 0;i < n; i += d){
        ll opt1 = p;
        ll opt2 = ps[min(i+d, n)] - ps[i];
        ans += min(opt1, opt2);
    }
    cout << ans << "\n";
}
