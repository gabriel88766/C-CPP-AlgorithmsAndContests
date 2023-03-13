#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binpow(ll a, ll b, ll m = MOD){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll divmod(ll a, ll b, ll m = MOD){
    return (a * binpow(b, m-2, m)) % m;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> dp(n+1), v(n);
        dp[0] = 0;
        int cnt = 0, cnt2 = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i] == 1) cnt++;
        }
        ll aux = (n*(n-1)) % MOD;
        aux = divmod(aux, 2);
        for(int i=0;i<(n-cnt);i++){
            if(v[i] == 1) cnt2++;
        }
        for(ll i=1;i<=cnt2;i++){
            ll aux2 = (i*i) % MOD;
            dp[i] = ( dp[i-1] + divmod(aux, aux2) ) % MOD;
        }
        cout << dp[cnt2] << "\n";
    }
}
