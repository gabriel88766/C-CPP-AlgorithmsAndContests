#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
ll dp[2][1 << 20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    assert(pr.size() == 20);
    dp[0][0] = 1;
    ll a, b;
    cin >> a >> b;
    int lb = 0;
    for(ll i=a;i<=b;i++){
        ll cm = 0;
        for(int j=0;j<20;j++){
            if(!(i % pr[j])){
                cm |= (1 << j);
            }
        }
        int bc = (i - a + 1) % 2;
        lb = bc;
        for(int j=0;j<(1 << 20);j++) dp[bc][j] = 0;
        for(int j=0;j<(1 << 20);j++){
            dp[bc][j] += dp[bc^1][j]; //don't put the next
            if(!(cm & j)){
                dp[bc][j | cm] += dp[bc^1][j]; //put the next number;
            } 
        }
    }
    ll ans = 0;
    for(int j=0;j<(1 << 20);j++) ans += dp[lb][j];
    cout << ans << "\n";
}
