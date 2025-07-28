#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double dp[100005];  
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    dp[n] = 0;
    double x = 1.0/n;
    for(int i=n-1;i>=1;i--){
        int good = n - i;
        int bad = i;
        //dp[i] * (1 - bad/n) = 1 + good/n * dp[i+1];
        dp[i] = 1 + good * x * dp[i+1];
        dp[i] /= (1 - bad * x);
    }
    cout << fixed << setprecision(10) << dp[1] << "\n";
}
