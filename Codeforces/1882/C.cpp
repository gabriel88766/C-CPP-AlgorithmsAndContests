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
        ll ans = 0;
        for(int i=0;i<n;i++) cin >> v[i];
        for(int i=2;i<n;i++) if(v[i] > 0) ans += v[i];
        //pos a0+a1 or a0 or none
        if(n > 1) ans += max(v[0]+v[1], max(v[0], 0LL));
        else ans += max(v[0], 0LL);
        cout << ans << "\n";
    }
}
