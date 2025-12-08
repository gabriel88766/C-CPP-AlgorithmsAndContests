#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[2][61];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll x, y;
    cin >> x >> y;
    if(x >= y) cout << abs(x-y) << "\n";
    else{
        ll ans = INF_LL;
        for(int i=0;;i++){
            ll mtp = 1LL << i;
            ll dif = abs(mtp*x - y);
            ll cur = i;
            ll cm = dif / (1LL << i);
            cur += cm;
            dif -= cm * (1LL << i);
            // cur += solve(dif, i);
            //now dp ...
            string s1, s2;
            ll neg = -dif;
            for(int j=0;j<=i;j++){
                if(dif & (1LL << j)) s1 += '1';
                else s1 += '0';
            }
            for(int j=0;j<=i;j++){
                if(neg & (1LL << j)) s2 += '1';
                else s2 += '0';
            }
            for(int j=0;j<=i;j++){ // I want dp[0][i]
                dp[0][i] = dp[1][i] = INF_LL;
            }
            for(int j=0;j<=i;j++){
                for(int u=0;u<=j;u++){
                    int q1 = 0;
                    int q2 = 0;
                    for(int k=u;k<=j;k++){
                        if(s1[k] == '1') q1++;
                        if(s2[k] == '1') q2++;
                    }
                    if(u == 0){
                        dp[0][j] = q1;
                        dp[1][j] = q2;
                    }else{
                        dp[0][j] = min({dp[0][j], dp[1][u-1] + q1 + 1});
                        dp[1][j] = min({dp[1][j], dp[0][u-1] + q2 + 1});
                    }
                }
            }
            cur += dp[0][i];
            ans = min(ans, cur);
            if(mtp*x > y) break;
        }
        cout << ans << "\n";
    }
}
