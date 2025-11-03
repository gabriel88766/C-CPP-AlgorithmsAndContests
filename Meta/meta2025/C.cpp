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
    // freopen("narrowing_down_input.txt", "r", stdin); //test input
    // freopen("out.txt", "w", stdout); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        vector<int> v(n+1);
        // for(int i=1;i<=n;i++) cin >> v[i];
        map<ll, ll> mp;
        mp[0] = 1;
        ll ans = 0;
        for(ll i=1;i<=n;i++){
            ans += i * (n-i+1);
        }
        int x = 0;
        for(int i=1;i<=0;i++){
            x ^= v[i];
            ans -= (mp[x] * (mp[x]+1))/2;
            mp[x]++;
        }
        cout << "Case #" << i << ": ";
        cout << ans << "\n";
    }
}
