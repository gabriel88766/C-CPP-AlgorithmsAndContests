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
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> u(n), v(m);
    vector<ll> psv;
    for(int i=0;i<n;i++) cin >> u[i];
    for(int i=0;i<m;i++) cin >> v[i];
    sort(v.begin(), v.end());
    psv = v;
    for(int i=1;i<m;i++) psv[i] += psv[i-1];
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll qt = upper_bound(v.begin(), v.end(), p-u[i]) - v.begin();
        if(qt > 0) ans += psv[qt-1];
        ans += p*(m-qt);
        ans += qt*u[i];
    }
    cout << ans << "\n";
}
