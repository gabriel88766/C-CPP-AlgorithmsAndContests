#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5;
ll dp[N];
unordered_map<ll, ll> dp2;

ll solve(ll n, ll x){
    if(n < N) return dp[n];
    if(dp2.count(n)) return dp2[n];
    ll ans = INF_LL;
    for(int i = 2; i <= 130-x-2;i++){
        if(n % i == 0) ans = min(ans, solve(n/i, x + i + 2) + i + 2);
    }
    for(int i=1;i<=130-x;i++){
        ans = min(ans, solve(n-i, x + i) + i);
    }
    return dp2[n] = ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<N;i++){
        dp[i] = dp[i-1] + 1;
        for(int j=2;j<=62;j++){
            if(i % j == 0){
                dp[i] = min(dp[i], dp[i/j] + j + 2);
            }
        }
    }
    ll n;
    cin >> n;
    cout << solve(n, 0) << "\n";
}
