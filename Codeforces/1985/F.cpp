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
        ll h, n;
        cin >> h >> n;
        vector<ll> a(n), c(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> c[i];
        ll lo = 0, hi = 5e10;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            ll tt = 0;
            for(int i=0;i<n;i++){
                //1 + k*c[i] <= mid
                // k = (mid-1)/c[i];
                ll cur = (mid-1)/c[i] + 1;
                if(mid == 0) cur = 0;
                cur *= a[i];
                tt = min(INF_LL, tt + cur); //avoid overflow
            }
            if(tt >= h) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
