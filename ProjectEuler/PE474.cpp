#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
// const ll INF_LL = 0x3f3f3f3f3f3f3f3f MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll M = 12500; //1000 or 12500
const ll C = 8179;//123 or 8179
const ll N = 1000000; //50 or 1000000
const ll MOD = 10'000'000'000'000'061LL;

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

int p[1000001];
__int128 dp[M], aux[M], aux2[M];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[1] = 1;
    for(int i=2;i<=N;i++){
        if(!p[i]){
            for(int j=2*i;j<=N;j+=i) p[j] = 1;
            int fc = 0;
            ll cur = i;
            while(cur <= N){
                fc += N / cur;
                cur *= i;
            }
            for(int j=0;j<M;j++) aux[j] = aux2[j] = 0;
            for(int j=0;j<=fc;j++){
                aux[binpow(i, j, M)]++;
            }
            vector<int> idx;
            for(int j=0;j<M;j++) if(aux[j] != 0) idx.push_back(j);
            for(int j=0;j<M;j++){
                for(auto &k : idx){
                    aux2[(j*k) % M] = (aux2[(j*k) % M] + aux[k] * dp[j]) % MOD;
                }
            }
            for(int j=0;j<M;j++) dp[j] = aux2[j];

        }
    }
    __int128 ans = dp[C];
    ans %= MOD;
    ll rans = ans;
    cout << rans << "\n";
}
