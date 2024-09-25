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
        vector<int> h(n);
        for(int i=0;i<n;i++) cin >> h[i];
        ll ans = INF_LL;
        int mv = *max_element(h.begin(), h.end());
        for(int i=mv;i<=mv+1;i++){
            ll lo = 0, hi = 1e15;
            ll aux = 0;
            ll sum = 0;
            for(int j=0;j<n;j++){
                if((i - h[j]) % 2) aux++;
                sum += (i-h[j])/2;
            }
            while(lo != hi){
                ll mid = lo + (hi - lo)/2;
                bool ok = true;
                ll odd = mid / 2 + mid % 2;
                ll even = mid / 2;
                if(odd < aux) ok = false;
                even += (odd - aux) / 2;
                if(even < sum) ok = false;
                if(ok) hi = mid;
                else lo = mid + 1;
            }
            ans = min(ans, lo);
        }
        cout << ans << "\n";
    }
}
