#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


int dp[205][5005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        int c2 = 0, c5 = 0;
        while(!(x % 2)){
            c2++;
            x /= 2;
        }
        while(!(x % 5)){
            c5++;
            x /= 5;
        }
        vp.push_back({c5, c2});
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n*25;j++){
            dp[i][j] = -INF_INT;
        }
    }
    dp[0][0] = 0;
    //well, at most 60*200 = 12000 for 2^x
    //at most 25 * 200 = 5000 for 5^x
    //at most 5000 zeroes
    for(auto [a, b]:  vp){
        for(int i=k;i>=1;i--){
            for(int j=a;j<=n*25;j++){
                if(dp[i-1][j-a] == -INF_INT) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][j-a] + (b-a));
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=n*25;i++){
        ans = max(ans, min(i, i + dp[k][i]));
    }
    cout << ans << "\n";
}
