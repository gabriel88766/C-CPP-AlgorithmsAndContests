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
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> ps(n+1);
        for(int i=1;i<=n;i++){
            cin >> ps[i];
            ps[i] += ps[i-1];
        }
        ll ans = 0;
        for(int i=0;i<k;i++){
            if(ps[n]*i >= x) ans += n;
            else if(ps[n] * (i+1) >= x){
                for(int j=0;j<n;j++){
                    if(ps[n]*(i+1)-ps[j] >= x) ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}
