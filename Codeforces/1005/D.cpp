#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n+1, 0);
    for(int i=1;i<=n;i++){
        if(i == 1){
            int dg1 = s[i-1]-'0';
            if(dg1 % 3 == 0) dp[1] = 1;
        }else if(i == 2){
            int dg1 = s[i-1]-'0', dg2 = s[i-2]-'0';
            if(dg1 % 3 == 0) dp[2] = dp[1] + 1;
            else if((dg1 + dg2) % 3 == 0) dp[2] = 1;
            else dp[2] = dp[1];
        }else{
            int dg1 = s[i-1]-'0', dg2 = s[i-2]-'0', dg3 = s[i-3]-'0';
            if(dg1 % 3 == 0) dp[i] = dp[i-1] + 1;
            else if((dg1 + dg2) % 3 == 0) dp[i] = dp[i-2] + 1;
            else if((dg1 + dg2 + dg3) % 3 == 0) dp[i] = dp[i-3] + 1;
            dp[i] = max(dp[i], dp[i-1]);
        }
    }
    cout << dp[n] << "\n";
}   
