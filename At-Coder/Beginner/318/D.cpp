#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll adj[17][17];

ll dp[1 << 16];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cin >> adj[i][j];
        }
    }
    dp[0] = 0;
    for(int i=1;i < (1 << n); i++){
        if(__builtin_popcount(i) == 1) dp[i] = 0;
        else{
            for(int j=0;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if((i & (1 << j)) &&(i & (1 << k))){
                        int old = i ^ (1 << j) ^ (1 << k);
                        dp[i] = max(dp[i], dp[old] + adj[j][k]);
                    }
                }
            }
        }
    }


    cout << dp[(1<<n) - 1] << "\n";
}
