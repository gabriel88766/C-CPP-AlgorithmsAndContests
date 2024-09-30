#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e7+5;
int pr[N];
ll sum[N];
void sieve(int n){
    for(ll i=2;i<=n;i++){
        if(!pr[i]){
            for(ll j = i*i;j<=n;j+=i) pr[j] = 1;
            sum[i] = i;
        }
        sum[i] += sum[i-1];
    }
}

//S(v, p) is the sum of integers up to v, when sieve until p.
//S(v, p) = S(v, p-1) - p*(S(v, p-1) - S(p-1, p-1));
map<ll, map<ll, __int128>> dp;
__int128 calc(__int128 n, ll p = 2e7){
    if(n == 1) return 0;
    if(dp.count(n) && dp[n].count(p)) return dp[n][p];
    if(p*p >= n && n < N) return dp[n][p] = sum[n];
    __int128 ans = (n * (n+1)) / 2;
    ans -= 1;
    ll sqt = sqrt(n);
    while(sqt*sqt>n)sqt--;
    while((sqt+1)*(sqt+1) <= n) sqt++;
    for(ll i=2;i<=min(p, sqt);i++){
        if(!pr[i]){
            ans -= i * (calc(n/i, i-1) - sum[i-1]);
        }
    }
    return dp[n][p] = ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n = 2'000'000'000'000;
    sieve(N-1);
    __int128 ans = calc(n);
    ll aux = 1e18;
    ll hi = ans / aux;
    ll lo = ans % aux;
    cout << hi << " " << lo << "\n";
}
