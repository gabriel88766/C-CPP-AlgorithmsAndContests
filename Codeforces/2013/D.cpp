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
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        ll mn = INF_LL, mx = 0;
        ll s = 0;
        for(int i=1;i<=n;i++){
            s += v[i];
            mn = min(mn, s/i);
        }
        s = 0;
        for(int i=n;i>=1;i--){
            s += v[i];
            ll cur = (s+n-i)/(n-i+1);
            mx = max(mx, cur);
        }
        cout << mx-mn << "\n";
    }
}
