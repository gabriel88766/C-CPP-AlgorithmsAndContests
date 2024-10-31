#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool dp[82][82][15000]; //100MB
int g1[82][82], g2[82][82];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> g1[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> g2[i][j];
            if(i == 1 && j == 1){
                dp[i][j][abs(g2[i][j] - g1[i][j])] = true;
            }else{
                int dif = abs(g2[i][j] - g1[i][j]);
                for(int s=0;s<15000;s++){
                    if(dp[i-1][j][s] || dp[i][j-1][s]){
                        dp[i][j][abs(s-dif)] = true;
                        dp[i][j][s+dif] = true;
                    }
                }
                
            }
        }
    }
    for(int d=0;d<15000;d++){
        if(dp[h][w][d]){
            cout << d << "\n";
            break;
        }
    }
}
