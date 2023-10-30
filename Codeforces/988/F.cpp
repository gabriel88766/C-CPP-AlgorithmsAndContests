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
    int a, n, m;
    cin >> a >> n >> m;
    vector<bool> umb(a+1, false);
    for(int i=0;i<n;i++){
        int l, r;
        cin >> l >> r;
        for(int j=l;j<r;j++) umb[j] = true;
    }
    vector<int> bumb(a+1, INF_INT);
    for(int i=0;i<m;i++){
        int aux1, aux2;
        cin >> aux1 >> aux2;
        bumb[aux1] = min(bumb[aux1], aux2);
    }
    vector<vector<int>> dp(a+1, vector<int>(2, INF_INT));
    dp[0][0] = 0;
    for(int i=1;i<=a;i++){
        for(int j=0;j<i;j++){
            if(bumb[j] != INF_INT){
                dp[i][1] = min(dp[i][1], dp[j][0] + bumb[j]*(i-j));
            }
        }
        if(!umb[i-1]) dp[i][0] = dp[i-1][0];
        else dp[i][0] = dp[i][1];
    }
    if(dp[a][0] == INF_INT) cout << "-1\n";
    else cout << dp[a][0] << "\n";
}
