#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
ll dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 0xFF, sizeof(dp));

    dp[1] = 1;
    for(int a=3;a<=500000;a+=2){
        if(dp[a] == -1) dp[a] = dp[a-2] + 1;
        else dp[a] = min(dp[a], dp[a-2] + 1);
        for(int b=1;b<=a;b+=2){
            if(a*b <= 500000){
                if(dp[a*b] == -1) dp[a*b] = dp[a] + dp[b] - 1;
                else dp[a*b] = min(dp[a*b], dp[a] + dp[b] - 1);
            }else break;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}
