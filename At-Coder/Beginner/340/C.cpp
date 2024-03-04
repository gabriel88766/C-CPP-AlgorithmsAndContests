#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


map<ll, ll> dp;
ll calcdp(ll n){
    ll x1 = n/2;
    ll x2 = n - x1;
    if(!dp.count(x1)) dp[x1] = calcdp(x1);
    if(!dp.count(x2)) dp[x2] = calcdp(x2);
    return dp[n] = dp[x1] + dp[x2] + n;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    dp[1] = 0;
    cout << calcdp(n) << "\n";
}
