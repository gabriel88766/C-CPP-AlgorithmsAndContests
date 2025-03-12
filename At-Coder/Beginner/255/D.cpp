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
    int n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++){
        ps[i] = ps[i-1] + v[i];
    }
    v[0] = -1;
    for(int i=0;i<q;i++){
        ll x;
        cin >> x;
        auto ind = lower_bound(v.begin(), v.end(), x) - v.begin();
        ll ans = x * (ind - 1) - ps[ind-1];
        // cout << ans << " " << ind << "\n";
        if(ind <= n){
            ans += ps[n] - ps[ind - 1];
            ans -= x * (n - ind + 1);
        }
        cout << ans << "\n";
    }
}
