#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binpow(ll a, ll  b, ll  m = MOD){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll divmod(ll a, ll b){
    return ((a%MOD) * binpow(b, MOD-2, MOD))%MOD;
}

ll dp[1000005];

ll rec(ll a, ll n, ll aux = 1){
    if(a == 0) return 0;
    if(a == n){
        return dp[a] = (rec(n-1, n) + aux) % MOD;
    }
    aux = (1 + divmod(n-a, a) * (aux+1)) % MOD;
    return dp[a] = (rec(a-1, n, aux) + aux) % MOD;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, qt=0;
        cin >> n;
        for(int i=1;i<=n;i++) dp[i] = 0;
        string a, b;
        cin >> a >> b;
        for(int i=0;i<n;i++) if(a[i] != b[i]) qt++;
        rec(n, n);
        cout << dp[qt] << "\n";
    }
}
