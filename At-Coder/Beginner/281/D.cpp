#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 105;
ll dp[N][N];
int v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 0xFF, sizeof(dp));
    dp[0][0] = 0;
    int n, k, d;
    cin >> n >> k >> d;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        for(int j=k;j>=1;j--){
            //dp[j][l] = max(dp[j][l], dp[j-1][(l - x) % d] + x);
            for(int l=0;l<d;l++){
                int r = l - x;
                r %= d;
                if(r < 0) r += d;
                if(dp[j-1][r] != -1) dp[j][l] = max(dp[j][l], dp[j-1][r] + x);
            }
        }
    }
    cout << dp[k][0] << "\n";
}
