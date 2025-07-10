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
    //freopen("in", "r", stdin); //
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vp;
    for(int i=0;i<m;i++){
        ll a, c;
        cin >> a >> c;
        vp.push_back({c, a});
    }
    sort(vp.begin(), vp.end());
    ll ans = 0;
    for(auto [c, a] : vp){
        ll g = gcd(n, a);
        if(g != n){
            ans += (n - g) * c;
            n = g;
        }
    }
    if(n == 1)cout << ans << "\n";
    else cout << "-1\n";
}
