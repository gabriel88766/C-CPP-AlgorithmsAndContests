#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll x[201];
ll l[201];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=n;i++) cin >> l[i];
    ll ans = 0;
    ll lo = -3e18, hi = x[1]-1;
    for(int i=n;i>=1;i--){
        lo = max(lo, x[i]-l[i]);
    }
    if(hi >= lo) ans += (hi-lo+1);
    lo = x[n], hi = 3e18;
    for(int i=1;i<=n;i++){
        hi = min(hi, x[i] + l[n-i+1]);
    }
    if(hi >= lo) ans += (hi-lo+1);



    for(int i=1;i<n;i++){
        //between x[i] and x[i+1];
        ll lo, hi, nxtlo = x[i];
        while(nxtlo < x[i+1]){
            lo = nxtlo;
            hi = x[i+1]-1;
            vector<bool> used(n+2, false);
            bool ok = true;
            int p = 1;
            for(int j=i;j>=1;j--){
                while(p <= n && (lo-l[p]) > x[j]) p++;
                if(p == (n+1)){
                    ok = false;
                    break;
                }
                used[p] = true;
                hi = min(hi, l[p]+x[j]);
                p++;
            }
            if(!ok) break;
            nxtlo = hi+1;
            int cur = n;
            for(int j=n;j>i;j--){
                while(used[cur]) cur--;
                //x[j]-lo <= l[cur]
                lo = max(lo, x[j]-l[cur]);
            }
            if(hi >= lo){
                ans += (hi-lo+1);
            } 
        }
    }
    cout << ans << "\n";
}
