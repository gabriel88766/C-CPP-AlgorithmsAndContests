#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll a, b, c;
    cin >> a >> b >> c;
    a = (a*(a+1))/2;
    b = (b*(b+1))/2;
    c = (c*(c+1))/2;
    a %= MOD;
    b %= MOD;
    c %= MOD;
    ll ans = (a * b) % MOD;
    ans = (ans * c) % MOD;
    cout << ans;
}
