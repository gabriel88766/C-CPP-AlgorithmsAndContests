#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
ll fat[N], invfat[N];

ll binpow(ll a, ll  b, ll  m = MOD){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void init(){
    fat[0] = 1;
    for(int i=1;i<N;i++) fat[i] = (fat[i-1] * i) % MOD;
    for(int i=0;i<N;i++){
        invfat[i] = binpow(fat[i], MOD - 2);
    }
}

ll bino(ll a, ll b){
    return (((fat[a] * invfat[a-b])%MOD) * invfat[b]) % MOD;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    init();
    ll n, k;
    cin >> n >> k;
    vector<ll> dp(k+1);
    for(int i=1;i<=k;i++){
        dp[i] = (bino(k, i) * binpow(i, n) - dp[i-1] + MOD) % MOD;
    }
    cout << dp[k];
}
