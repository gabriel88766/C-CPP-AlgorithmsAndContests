#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ps(n+1);
        ps[0] = 0;
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            ps[i] = ps[i-1] + aux;
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            int cur = ps[i] - ps[i-1];
            if(cur){
                int tt1 = ps[n] - ps[i], tt0 = n-i;
                tt0 -= tt1;
                ans += tt0;
            }
        }
        ll aux = ans;
        for(int i=1;i<=n;i++){
            int cur = ps[i] - ps[i-1];
            ll dif = 0;
            int tt1r = ps[n] - ps[i], tt0r = n-i, tt1l = ps[i-1], tt0l = i-1;
            tt0r -= tt1r;
            tt0l -= tt1l;
            if(cur){ //1 => 0
                dif += tt1l;
                dif -= tt0r;
            }else{
                dif += tt0r;
                dif -= tt1l;
            }
            ans = max(ans, aux + dif);
        }
        cout << ans << "\n";
    }
}
 