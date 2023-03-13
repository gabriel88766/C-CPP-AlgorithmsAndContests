#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 8192;//max value of xor.

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

ll pre[15][5005];
ll dp[5005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    for(int i=0;i<15;i++){
        int aux = 1 << i;
        for(int j=1;(2*j*aux)<=m;j++){
            if(2*j > n) break;
            pre[i][2*j*aux] = nCr(n, 2*j);
        }
    }
    dp[0] = 1;
    for(int i=0;i<15;i++){
        for(int j=m;j>=0;j--){
            for(int k=1;k<=j;k++){
                dp[j] = (dp[j] + dp[j-k]*pre[i][k]) % MOD;
            }
        }
    }
    cout << dp[m];
}
