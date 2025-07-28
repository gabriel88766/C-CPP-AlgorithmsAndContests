#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

map<ll, double> dp;
ll a, m, x, y;
double solve(ll n){
    if(dp.count(n)) return dp[n];
    double opt1 = ((solve(n/2) + solve(n/3) + solve(n/4) + solve(n/5) + solve(n/6))/6 + y)*1.2;
    double opt2 = solve(n/a) + x;
    return dp[n] = min(opt1, opt2);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0] = 0;
    cin >> m >> a >> x >> y;
    cout << fixed << setprecision(15) << solve(m) << "\n";
}
