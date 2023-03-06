#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1 << 21];
int adj[21][21];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> adj[i][j];
        }
    }
    dp[0] = 1;
    for(int j=0;j < (1 << n); j++){   
        int h = __builtin_popcount(j);
        for(int i=0;i<n;i++){
            if(!adj[h][i] || j & (1 << i)) continue;
            dp[j | (1 << i)] = (dp[j | (1 << i)] + dp[j]) % MOD;
        } 
    }
        
    
    cout << dp[(1 << n)-1];
}
