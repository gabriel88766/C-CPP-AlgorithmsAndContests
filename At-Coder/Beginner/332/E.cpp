#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double dp[1 << 15][16];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    double avg;
    for(int i=0;i<n;i++){
        cin >> v[i];
        avg += v[i];
    }
    avg /= d;
    for(int i=0;i<(1 << n); i++){
        for(int j=0;j<=d;j++){
            dp[i][j] = 1e50;
        }
    }
    for(int i=0;i < (1 << n); i++){
        dp[i][1] = -avg;
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                dp[i][1] += v[j];
            }
        }
        dp[i][1] *= dp[i][1];
    }
    
    for(int m=0; m < (1 << n); m++){
        for (int s=m; s; s=(s-1)&m){ 
            for(int j=2;j<=d;j++){
                dp[m][j] = min(dp[m][j], dp[s][j-1] + dp[m^s][1]);
            }
        }
    }
    cout << fixed << setprecision(15) << dp[(1 << n)-1][d]/d << "\n";
}
