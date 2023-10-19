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
        ll w, f;
        cin >> w >> f;
        int n;
        cin >> n;
        bitset<1000001> bs;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        ll sum = 0;
        for(int i=0;i<n;i++) sum += a[i];
        bs[0] = 1;
        for(int i=0;i<n;i++){
            bs |= (bs << a[i]);
        }
        ll ans = INF_LL;
        for(int i=0; i<= 10000*n; i++){
            if(!bs[i]) continue;
            ll d = max((i-1)/w + 1, (sum-i-1)/f + 1);
            ans = min(d, ans);
        }
        cout << ans << "\n";
    }
}