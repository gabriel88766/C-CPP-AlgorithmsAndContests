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
        vector<ll> a(n);
        ll sum = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        ll cps = 0, btt = 0, mxodd = 0, mxeven = 0;
        for(int i=0;i<n;i++){
            if(i % 2 == 0) cps += a[i], mxeven = max(mxeven, cps);
            else cps -= a[i], mxodd = max(mxodd, cps);
            //select any previous index and invert
            if(i % 2 == 0) btt = max(btt, 2*(mxeven - cps));
            else btt = max(btt, 2*(mxodd - cps));
            // mx = max(mx, cps);
        }
        // cout << sum << " " << cps << " " << btt << " ";
        ll ans = sum + cps + btt;
        ans /= 2;
        cout << ans << "\n";
    }
}
