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
    vector<ll> v(n+1), a(n+1), b(n+1);
    vector<ll> psa(n+1), psb(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int st = 1'000'000'000LL;
    a[1] = st;
    b[1] = v[1] - st;
    for(int i=2;i<=n;i++){
        ll v1 = a[i-1];
        ll v2 = v[i] - v1;
        if(v2 > b[i-1]){
            ll dif = v2 - b[i-1];
            v1 += dif;
            v2 -= dif;
        }
        a[i] = v1;
        b[i] = v2;
    }
    reverse(b.begin() + 1, b.end());
    for(int i=1;i<=n;i++){
        psa[i] = psa[i-1] + a[i];
        psb[i] = psb[i-1] + b[i];
    }
    //proved by ac = one of the numbers must be 0
    vector<ll> delt;
    for(int i=1;i<=n;i++){
        delt.push_back(abs(a[i]));
        delt.push_back(abs(b[i]));
    }
    ll ans = INF_LL;
    b[0] = -INF_LL;
    for(auto x : delt){ //try all deltas
        int p1 = lower_bound(a.begin(), a.end(), x) - a.begin();
        int p2 = lower_bound(b.begin(), b.end(), -x) - b.begin();
        ll cur = 0;
        cur = (p1-1) * x - psa[p1-1];
        cur += psa[n] - psa[p1-1] - (n-p1+1) * x;
        // cout << cur << " ";
        cur += (p2 - 1) * (-x)  - psb[p2-1];
        // cout << cur << " " << x <<" " << psb[p2-1] << "\n";
        cur += psb[n] - psb[p2-1] - (n - p2 + 1) * (-x);
        // cout << cur << "\n";
        ans = min(ans, cur); 
    }   
    cout << ans << "\n";
}
