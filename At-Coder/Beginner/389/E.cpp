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
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    //first bin search to find highest cost
    vector<ll> vt(n);
    auto getv = [&](ll mc){
        for(int i=0;i<n;i++){
            //get the highest k such that (2*k - 1) * p[i] <= mc
            // 2*k - 1 <= mc/p[i]
            //k <= (mc/p[i] + 1)/2
            vt[i] = (mc/p[i] + 1)/2;
        }
    };
    ll lo = 1, hi = 1e18;
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        ll cst = 0;
        getv(mid);
        for(int i=0;i<n;i++){
            ll cn = vt[i];
            if(cn == 0) continue;
            if(INF_LL / cn > cn) cn *= cn;
            else cn = INF_LL;
            if(INF_LL / cn > p[i]) cn *= p[i];
            else cn = INF_LL;
            cst = min(INF_LL, cst + cn);
        }
        if(cst >= m) hi = mid;
        else lo = mid + 1;
    }
    //take all up to highest cost - 1;
    getv(lo - 1);
    ll ans = 0;
    ll ttc = 0;
    for(int i=0;i<n;i++){
        ttc += vt[i] * vt[i] * p[i];
        ans += vt[i];
    }
    ans += (m - ttc) / lo;
    cout << ans << "\n";
}
