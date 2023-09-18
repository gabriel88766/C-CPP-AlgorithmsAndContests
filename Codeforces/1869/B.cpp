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
    while(t--){
        ll n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pair<ll,ll>> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i].first >> v[i].second;
        }
        ll ans = abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
        ll mina = INF_LL, minb = INF_LL;
        for(int i=1;i<=k;i++){
            mina = min(mina, abs(v[a].first - v[i].first) + abs(v[a].second - v[i].second));
            minb = min(minb, abs(v[b].first - v[i].first) + abs(v[b].second - v[i].second));
        }
        ans = min(ans, mina+minb);
        cout << ans << "\n";
    }
}
