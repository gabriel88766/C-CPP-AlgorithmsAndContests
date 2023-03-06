#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 305, M = 200005; 

ll fat[N], invfat[N];
ll pot[M], v[M];
ll sum[N];

void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = (fat[i-1]*i) % MOD;
    }
    ll aux = MOD - 2, aux2 = fat[N-1];
    while(aux){
        if(aux & 1) invfat[N-1] = (invfat[N-1] * aux2) % MOD;
        aux2 = (aux2 * aux2) % MOD;
        aux >>= 1;
    }
    for(int i=N-2;i>=0;i--) invfat[i] = (invfat[i+1] * (i + 1)) % MOD;
}
ll nCr(ll a, ll b){
    return (((fat[a] * invfat[a-b]) % MOD) * invfat[b]) % MOD;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    init();
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) pot[i] = v[i], sum[1] += v[i];
    sum[1] %= MOD;
    sum[0] = n;
    for(int i=2;i<=300;i++){
        for(int j=1;j<=n;j++){
            pot[j] = (pot[j] * v[j]) % MOD;
            sum[i] = (sum[i] + pot[j]) % MOD;
        }
    }
    ll ans;
    for(int i=1;i<=k;i++){
        ans = 0;
        for(int j=0;j<i;j++){
            ll cur = (sum[j] * sum[i-j]) % MOD;
            cur = (cur + MOD - sum[i]) % MOD;
            if(j != 0) cur = cur*invfat[2] % MOD;
            ans = (ans + cur * nCr(i, j)) % MOD;
        }
        cout << ans << "\n";
    }
}
