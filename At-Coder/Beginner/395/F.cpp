#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int u[N], d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x;
    cin >> n >> x;
    for(int i=1;i<=n;i++) cin >> u[i] >> d[i];
    int mx = 2'111'111'111;
    for(int i=1;i<=n;i++) mx = min(mx, u[i] + d[i]);
    int lo = 2, hi = mx;
    auto check = [&](int mid){
        ll l = 0, r = mid;
        bool ok = true;
        for(int i=1;i<=n;i++){
            ll nl = max(0, mid - u[i]);
            ll nr = min(mid, d[i]);
            // cout << nl << " " << nr << " ";
            if(nl < l) nl = max(nl, l - x);
            if(nr > r) nr = min(nr, r + x);
            // cout << nl << " " << nr << "\n";
            if(nr >= nl){
                r = nr, l = nl;
            }else ok = false;
        }
        return ok;
    };
    while(lo != hi){
        int mid = lo + (hi - lo + 1)/2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    // cout << "\n\n";
    // check(6);
    ll ans = 0;
    for(int i=1;i<=n;i++) ans += u[i] + d[i] - lo;
    cout << ans << "\n";
}
