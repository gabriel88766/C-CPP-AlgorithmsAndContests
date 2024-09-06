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
        int n, q;
        cin >> n >> q;
        vector<ll> v(n), ps(n);
        for(int i=0;i<n;i++){
             cin >> v[i];
             ps[i] = v[i];
             if(i) ps[i] += ps[i-1];
        }
        for(int i=0;i<q;i++){
            ll l, r;
            cin >> l >> r;
            --l, --r;
            ll ar1 = l/n;
            ll ar2 = r/n;
            ll ans = 0;
            if(ar1 == ar2){
                ll fe = (ar1 + l%n) % n;
                ll le = (ar2 + r%n) % n;
                if(le >= fe){
                    ans += ps[le];
                    if(fe) ans -= ps[fe-1];
                }else{
                    ans += ps[le];
                    ans += ps[n-1];
                    ans -= ps[fe-1];
                }
            }else{
                ans += (ar2-ar1-1) * ps[n-1];
                ll fe = (ar1 + l%n) % n;
                ll le = ar1 - 1;
                if(le < 0) le += n;
                if(le >= fe){
                    ans += ps[le];
                    if(fe) ans -= ps[fe-1];
                }else{
                    ans += ps[le];
                    ans += ps[n-1];
                    ans -= ps[fe-1];
                }
                fe = ar2;
                le = (ar2 + r % n) % n;
                if(le >= fe){
                    ans += ps[le];
                    if(fe) ans -= ps[fe-1];
                }else{
                    ans += ps[le];
                    ans += ps[n-1];
                    ans -= ps[fe-1];
                }
                //ar1 begin in element 
            }
            cout << ans << "\n";
        }
    }
}
