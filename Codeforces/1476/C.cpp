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
        int n;
        cin >> n;
        vector<ll> a(n+1), b(n+1), c(n+1);
        ll ans = 0;
        for(int i=1;i<=n;i++) cin >> c[i];
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        ll lc = 0, oc = 0;
        for(int i=2;i<=n;i++){
            if(a[i] == b[i] || i == 2){
                lc = 2 + abs(a[i] - b[i]);
            }else{
                lc = max(lc + 1 + c[i-1] - abs(a[i] - b[i]), abs(a[i] - b[i]) + 2);
            }
            ans = max(ans, lc + c[i] - 1);
        }
        cout << ans << "\n";
    }
}
