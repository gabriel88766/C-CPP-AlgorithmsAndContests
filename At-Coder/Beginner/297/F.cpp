#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+2; //O(N) preprocessing, O(1) query
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
    if(b < 0) return 0;
    if(b > a) return 0;
    return (((fat[a] * invfat[a-b]) % MOD) * invfat[b]) % MOD;
}

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll divmod(ll a, ll b, ll m=MOD){
    return (a * binpow(b, m-2, m)) % m;
}

ll dp[1001][1001], dp2[1001][1001], ps[1001][1001];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    ll H, W, K;
    cin >> H >> W >> K;
    ll ans = 0;

    

    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            ps[i][j] = (ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + MOD) % MOD;
            dp2[i][j] = (dp2[i-1][j] + dp2[i][j-1] - dp2[i-1][j-1] + ps[i][j] + MOD) % MOD;
            dp[i][j] = nCr(i*j, K);
            dp[i][j] = (dp[i][j] - dp2[i][j] + MOD) % MOD;
            dp2[i][j] = (dp2[i][j] + dp[i][j]) % MOD;
            ps[i][j] = (ps[i][j] + dp[i][j]) % MOD;
        }
    }


    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            ll ttsq = (H-i+1)*(W-j+1);
            ll aux = (dp[i][j] * ttsq) % MOD;
            ans = (ans + aux*i*j) % MOD;          
        }
    }
    ans = divmod(ans, nCr(H*W, K));
    cout << ans;
}
