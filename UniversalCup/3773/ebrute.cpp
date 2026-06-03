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
    // freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<ll> val(n+1);
        for(int i=1;i<=n;i++){
            cin >> val[i];
            val[i] += val[i-1];
        }
        ll ans = 0;
        for(int i=1;i<=q;i++){
            ll x;
            cin >> x;
            ll ans = -INF_LL;
            for(ll l=0;l<n;l++){
                for(ll r=l+1;r<=n;r++){
                    ans = max(ans, val[r] - val[l] + (r - l) * x);
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
