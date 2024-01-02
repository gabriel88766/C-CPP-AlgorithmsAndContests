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
        ll k;
        cin >> n >> k;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        if(v.back() == v[0]){
            cout << "0\n";
            continue;
        }
        if(v[0] > k){
            ll g = 0;
            for(int i=0;i<n;i++) g = gcd(v[i]-k, g);
            ll ans = 0;
            for(int i=0;i<n;i++){
                //everything k + g
                ans += (v[i] - k)/g - 1;
            }
            cout << ans << "\n";
        }else if(v.back() < k){
            ll g = 0;
            for(int i=0;i<n;i++) g = gcd(k-v[i], g);
            ll ans = 0;
            for(int i=0;i<n;i++){
                //everything k + g
                ans += (k-v[i])/g - 1;
            }
            cout << ans << "\n";
        }else cout << "-1\n";
    }
}
