#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Fraction{
    ll a, b;
    bool operator< (const Fraction &f) const {
        __int128 x1 = a, x2 = b;
        x1 *= f.b, x2 *= f.a;
        return x1 < x2;
    }
};
const int N = 1e5+2;

Fraction dp[2][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        dp[1][i] = dp[0][i-1];
        auto x1 = dp[1][i-1];
        auto x2 = dp[0][i-1];
        x1.b++;
        x2.b++;
        x1.a += v[i];
        x2.a += v[i];
        if(x1 < x2) dp[0][i] = x2;
        else dp[0][i] = x1;
        cout << dp[0][i].a << " " << dp[0][i].b << " - ";
    }
    double ans;
    if(dp[0][n] < dp[1][n]){
        ans = dp[1][n].a;
        ans /= dp[1][n].b;
    }else{
        ans = dp[0][n].a;
        ans /= dp[0][n].b;
    }
    cout << ans << "\n";
}
