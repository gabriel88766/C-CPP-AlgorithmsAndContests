#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[205][13];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0][0] = 1;
    int l;
    cin >> l;
    for(int i=1;i<=l;i++){
        for(int j=0;j<i;j++){
            for(int sz = 0;sz<12;sz++){
                dp[i][sz+1] += dp[j][sz];
            }
        }
    }
    cout << dp[l][12] << "\n";
}   
