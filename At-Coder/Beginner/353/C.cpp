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
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++){
        ps[i] = ps[i-1] + v[i];
    }
    ll ans = 0;
    for(int i = 1;i < n;i++){
        int x = 0;
        for(int j = n; j >= 1; j >>= 1){
            while(x + j <= n && v[x + j] + v[i] < 100'000'000) x += j;
        }
        ans += ps[n] - ps[i] + v[i] * (n - i);
        ans -= 100'000'000LL * (n - max(i, x));
    }
    cout << ans << "\n";
}
