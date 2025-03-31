#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e4+1;
double dp[N][21];
pair<int, int> cd[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //skip at most 20 checkpoints!
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cd[i].first >> cd[i].second;
        for(int j=0;j<=20;j++) dp[i][j] = 1e20;
        if(i == 1){
            dp[1][0] = 0;
        }else{
            for(int j=max(1, i-21);j<=i-1;j++){
                int sk = i - j - 1;
                double df = sqrt(pow(cd[i].first - cd[j].first, 2) + pow(cd[i].second - cd[j].second, 2));
                for(int s=0;s<=20;s++){
                    if(s + sk <= 20){
                        dp[i][s+sk] = min(dp[i][s+sk], dp[j][s] + df);
                    }else break;
                }
            }
        }
    }
    double ans = dp[n][0];
    for(int i=1;i<=20;i++){
        dp[n][i] += (1 << (i-1));
        ans = min(ans, dp[n][i]);
    }
    cout << fixed << setprecision(10) << ans << "\n";
}
