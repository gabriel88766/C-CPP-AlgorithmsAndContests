#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 505, N = 100000;
ll dp[M][M], v[M];
int n;

ll fat[N], invfat[N];
void init(){ //MOD must be prime, or aux = phi(n)-1
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
    string t, s;
    cin >> s;
    t = " " + s;
    n = s.size();
    if(n % 2){
        cout << "0\n";
        return 0;
    }
    for(int i=1;i<=n;i++) dp[0][i] = 1;
    init();
    for(int i=2;i<=n;i+=2){
        for(int j=1;j<=(n-i+1);j++){
            if(t[j] == t[j+i-1]) dp[i][j] += dp[i-2][j+1];
            for(int k=2;k<i;k+=2){
                if(dp[k][j] && dp[i-k][j+k]) dp[i][j] += nCr(dp[k][j]*k/2+dp[i-k][j+k]*((i-k)/2), dp[k][j]*k/2);
                dp[i][j] %= MOD;
            }
            cout << dp[i][j] << " \n"[j == (n-i+1)];
        }
    }
    cout << dp[n][1];
}
 