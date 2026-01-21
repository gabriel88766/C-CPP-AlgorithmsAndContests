#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int dp[N][31];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=1;i<=n;i++){
        int u = i;
        for(int jmp=n;jmp>=1;jmp>>=1){
            while(u - jmp > 0 && v[u - jmp] > v[i]/2) u -= jmp;
        }
        dp[i][0] = i;
        for(int j=1; j<= 30; j++) dp[i][j] = min(dp[i-1][j] + 1, dp[u-1][j-1]);
    }
    for(int i=0;i<=30;i++){
        if(dp[n][i] <= k){
            cout << i << " " << dp[n][i] << "\n";
            break;
        }
    }
}
