#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
bool dp[N][2][3];

// char pos[] = {'R', 'U', 'D'};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    int t;
    cin >> t;
    while(t--){
        dp[0][0][0] = true;
        int n;
        cin >> n;
        string s[2];
        cin >> s[0] >> s[1];
        for(int i=1;i<=n;i++){
            for(int j=0;j<2;j++){
                char c = s[j][i-1];
                if(dp[i-1][j][0]){ //Right
                    if(c >= '3'){
                        dp[i][j][1] = dp[i][j][2] = true;
                    }else{
                        dp[i][j][0] = true;
                    }
                }
            }
            for(int j=0;j<2;j++){
                char c = s[j][i-1];
                if(j == 1 && dp[i][j-1][2]){ // Down
                    if(c >= '3'){
                        dp[i][j][0] = true;
                    }
                }
                if(j == 0 && dp[i][j+1][1]){ //Up
                    if(c >= '3'){
                        dp[i][j][0] = true;
                    }
                }
            }
        }
        if(dp[n][1][0]) cout << "YES\n";
        else cout << "NO\n";


        for(int i=1;i<=n;i++) for(int j=0;j<2;j++) for(int k=0;k<3;k++) dp[i][j][k] = false;
    }
}
