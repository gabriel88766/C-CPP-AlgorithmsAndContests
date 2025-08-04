#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
int dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=2*n;i++){
        string s;
        cin >> s;
        int x = 0;
        while(s[x] != '.') x++;
        x++;
        auto num = stoi(s.substr(x, 3));
        for(int j=n;j>=0;j--){
            if(j != 0){
                dp[j] = min(dp[j] + (1000 - num) % 1000, dp[j-1] - num);
            }else{
                dp[0] += (1000 - num) % 1000;
            }
            cout << dp[j] << " ";
        }
        cout << "\n";
    }
    cout << dp[n] << "\n";
}
