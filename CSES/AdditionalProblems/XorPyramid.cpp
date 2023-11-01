#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<200005> dp[2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0][0] = 1;
    int n;
    cin >> n;
    n--;
    for(int i=18;i>=0;i--){
        if(n & (1 << i)){
            dp[1] = (dp[0] << (1 << i)) ^ dp[0];
            dp[0] = dp[1];
        }
    }
    n++;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        if(dp[1][i]) ans ^= v[i];
    }
    cout << ans << "\n";
}
