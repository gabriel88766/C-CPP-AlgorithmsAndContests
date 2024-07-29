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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        ll lo = 0, hi = 1'000'000'001;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;  
            ll tt = 0;
            for(int i=0;i<n;i++){
                //a-kb >= mid, find k
                // a - mid >= kb => k <= (a-mid)/b
                if(a[i] < mid) continue;
                tt += (a[i]-mid)/b[i] + 1;
            }
            if(tt < k) hi = mid;
            else lo = mid + 1;
        }
        ll ans = 0;
        ll tt = 0;
        for(int i=0;i<n;i++){
            if(a[i] < lo) continue;
            ll kx = (a[i]-lo)/b[i];
            tt += kx + 1;
            ans += ((kx+1) * (2*a[i] - b[i]*kx))/2;
        }
        if(lo) ans += (k - tt) * (lo - 1);
        cout << ans << "\n"; 
    }
}
