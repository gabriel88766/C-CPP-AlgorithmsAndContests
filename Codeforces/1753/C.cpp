#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll fat[200005];

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
void init(){
    fat[0] = 1;
    for(int i=1;i<=200000;i++) fat[i] = (i * fat[i-1]) % MOD;
}

ll bin(ll a, ll b){
    return divmod(fat[a], fat[b] * fat[a-b] );
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
    init();
    cin >> t;
    while(t--){
        int n, qt=0;
        cin >> n;
        for(int i=1;i<=n;i++) dp[i] = 0;
        vector<int> v(n);
        int cnt1 = 0, cnt1l = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i] == 1) cnt1++;
        }
        for(int i=0;i<(n-cnt1);i++){
            if(v[i] == 1) cnt1l++;
        }
        dp[0] = 0;
        rec(n, n-cnt1);
        cout << dp[cnt1l] << "\n";
    }
}
