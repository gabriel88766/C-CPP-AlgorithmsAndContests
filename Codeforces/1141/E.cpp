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
    ll H, n;
    cin >> H >> n;
    vector<ll> d(n+1);
    ll sr = 0;
    ll ans = INF_LL;
    for(int i=0;i<n;i++){
        cin >> d[i];
        sr += d[i];
    }
    sr = -sr;
    ll cs = 0;
    for(int i=0;i<n;i++){
        cs += d[i];
        if((cs*(-1)) >= H){
            ans = i+1;
            break;
        }
        if(sr > 0){
            ll cur;
            ans = min(ans, ((H-(cs*(-1))-1)/sr + 1)*n+i+1);
        }
    }
    if(ans != INF_LL) cout << ans;
    else cout << -1;
}
