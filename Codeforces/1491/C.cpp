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
        ll n;
        cin >> n;
        vector<ll> v(n+2), in(n+2, 0);
        for(int i=1;i<=n;i++) cin >> v[i];
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ll cur = max(1LL, v[i] - in[i]) - 1;
            ans += cur;
            in[i] += cur;
            if(in[i]){
                int r = min(n, i + v[i]);
                for(int j=i+2;j<=r;j++) in[j]++;
                if(in[i] >= v[i]){
                    in[i+1] += in[i] - v[i] + 1;
                }
            }
        }
        cout << ans << "\n";
    }
}
