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
    int k, n;
    cin >> n >> k;
    vector<int> v(k);
    for(int i=0;i<k;i++){
        cin >> v[i];
        v[i]--;
    }
    vector<pair<ll,ll>> vx(n);
    for(int i=0;i<n;i++) cin >> vx[i].first >> vx[i].second;
    ll mx = 0;
    for(int i=0;i<n;i++){
        ll minv = INF_LL;
        for(auto &x : v){
            ll dx = vx[x].first - vx[i].first;
            ll dy = vx[x].second - vx[i].second;
            ll cur = dx*dx + dy*dy;
            minv = min(minv, cur);
        }
        mx = max(mx, minv);
    }
    cout << fixed << setprecision(10) << sqrt(mx) << "\n";
}
