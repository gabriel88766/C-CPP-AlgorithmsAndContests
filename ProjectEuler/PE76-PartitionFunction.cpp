#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll N = 101;
ll P[N];
//O(N sqrt(N))
//There are easier way than proving euler pentagonal number theorem
//just use dp, commented.
void calc(int n = N-1){
    P[0] = 1;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            int v1 = i - (k*(3*k-1))/2;
            int v2 = i - (k*(3*k+1))/2;
            int s = (k+1) % 2 ? -1 : 1;
            if(v1 < 0 && v2 < 0) break;
            if(v1 >= 0) P[i] += s*P[v1];
            if(v2 >= 0) P[i] += s*P[v2];
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    calc();
    cout << P[100] - 1 << "\n";

    // O(n² log n), can be improved to O(n²) using prefix sums.
    // ll dp[101];
    // memset(dp, 0, sizeof(dp));
    // dp[0] = 1;
    // for(int i=1;i<=99;i++){
    //     for(int j=100;j>=i;j--){
    //         for(int u = 1; u*i <= j; u++){
    //             dp[j] += dp[j - u * i];
    //         }
    //     }
    // }
    // cout << dp[100] << "\n";
}
