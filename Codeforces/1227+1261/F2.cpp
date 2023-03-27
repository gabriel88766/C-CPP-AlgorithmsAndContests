#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll v[N];

ll fat[N], invfat[N];
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    init();
    ll k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> v[i];
    if(k == 1){
        cout << 0;
        return 0;
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(v[i-1] != v[i%n]){
            cnt++;
        }
    }
    ll ans = 0;
    for(int i=0;i<cnt;i++){
        ll aux = (nCr(cnt, i) * ((binpow(k-2, i) * binpow(k, n-cnt)) % MOD)) % MOD;
        ll aux2 = binpow(2, cnt-i);
        if((cnt-i) % 2 == 0) aux2 = (aux2 + MOD - nCr(cnt-i, (cnt-i)/2)) % MOD;
        aux2 = (aux2 * binpow(2, MOD-2)) % MOD;
        ans = (ans + aux*aux2) % MOD;
    }
    cout << ans;
}
