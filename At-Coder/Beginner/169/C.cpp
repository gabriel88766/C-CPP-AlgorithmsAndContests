#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll a;
    string b;
    cin >> a >> b;
    ll ans = 0;
    ans += a * (b[0] - '0');
    ans += (a * (b[2] - '0'))/10;
    ans += (a * (b[3] - '0'))/100;
    ll r = ((a * (b[2] - '0')) % 10) * 10 + (a * (b[3] - '0')) % 100;
    // cout << r << "\n";
    // int r = (a % 10) * 10 * (b[2] - '0') + (a % 100) * (b[3] - '0');
    ans += r/100;
    cout << ans << "\n";
}
