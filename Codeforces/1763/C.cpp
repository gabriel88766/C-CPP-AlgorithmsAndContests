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
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        if(n == 2){
            ll ans = v[0] + v[1];
            ans = max(ans, 2*abs(v[0]-v[1]));
            cout << ans << "\n";
            continue;
        }else if(n == 3){
            ll ans = v[0] + v[1] + v[2];
            ans = max(ans, 3*v[0]);
            ans = max(ans, 3*v[2]);
            {
                ans = max(ans, 3*abs(v[2]-v[1]));
                ans = max(ans, 3*abs(v[1]-v[0]));
                ans = max(ans, 2*abs(v[2]-v[1]) + v[0]);
                ans = max(ans, 2*abs(v[1]-v[0]) + v[2]);
            }
            cout << ans << "\n";
            continue;
        }
        ll m = *max_element(v.begin(), v.end());
        cout << m*n << "\n";
    }
}   
