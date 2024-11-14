#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e3+5;
ll dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<N;i++) dp[i] = -INF_LL;
    dp[0] = 0;
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        for(int j=m;j>=1;j--){
            dp[j] = max(dp[j], dp[j-1] + j * x);
        }
    }
    cout << dp[m] << "\n";
}
