#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[205][205][205];
ll pr[205][2];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s;
    cin >> n >> s;
    int k = s.size();
    for(int i=0;i<k;i++){
        string t = s.substr(0, i) + '(';
        for(int j=0;j<t.size();j++){
            if(t.substr(j, t.size()-j) == s.substr(0, t.size() - j)){
                pr[i][0] = t.size() - j;
                break;
            }
        }
        t = s.substr(0, i) + ')';
        for(int j=0;j<t.size();j++){
            if(t.substr(j, t.size()-j) == s.substr(0, t.size() - j)){
                pr[i][1] = t.size() - j;
                break;
            }
        }
    }
    dp[0][0][0] = 1;
    
    for(int i=1;i<=2*n;i++){
        for(int p=0;p<=2*n;p++){
            for(int j=0;j<k;j++){
                dp[i][p+1][pr[j][0]] = (dp[i][p+1][pr[j][0]] + dp[i-1][p][j]) % MOD;
                if(p) dp[i][p-1][pr[j][1]] = (dp[i][p-1][pr[j][1]] + dp[i-1][p][j]) % MOD;
            }
            dp[i][p+1][k] = (dp[i][p+1][k] + dp[i-1][p][k]) % MOD;
            if(p) dp[i][p-1][k] = (dp[i][p-1][k] + dp[i-1][p][k]) % MOD;
        }
    }
    cout << dp[2*n][0][k];
    
}
