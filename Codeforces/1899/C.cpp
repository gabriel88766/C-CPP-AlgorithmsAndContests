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
        ll ans = -INF_LL;
        ll cur = 0;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        for(int i=0;i<n;i++){
            if(i){
                if(abs(v[i] % 2) == abs(v[i-1] % 2)) cur = 0;
                if(cur < 0) cur = 0;
            }
            cur += v[i];
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}
