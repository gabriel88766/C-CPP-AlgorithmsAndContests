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
    ll ans = -INF_LL;
    ll cs = 0;
    vector<ll> v(n+1), ps(n+1);
    int cur = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
        if(cur != m) cur++;
        cs += v[i] * cur;
        if(cur == m){
            ans = max(ans, cs);
            cs -= ps[i] - ps[i-m];
        }
    }
    cout << ans << "\n";
}
