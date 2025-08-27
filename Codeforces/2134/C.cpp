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
        ll ans = 0;
        int n;
        cin >> n;
        vector<ll> v(n+2);
        v[n+1] = INF_INT;
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i+=2){
            if(i == 1){
                if(v[i] > v[i+1]){
                    ans += v[i] - v[i+1];
                    v[i] = v[i+1];
                }
            }else{
                ll s1 = v[i] + v[i-2];
                ll d1 = max(0LL, s1 - v[i-1]);
                ll d2 = max(0LL, v[i] - v[i+1]);
                // cout << d1 << " " << d2 << "\n";
                ll x = max(d1, d2);
                v[i] -= x;
                ans += x;
            }
        }
        cout << ans << "\n";
    }
}
