#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

ll dp[31][31][51];

void init(){
    memset(dp, 63, sizeof(dp)); //INF
    for(int i=1;i<=30;i++){
        for(int j=1;j<=30;j++){
            dp[i][j][0] = 0;
            if((i * j) <= 50) dp[i][j][i * j] = 0;
        }
    }
    for(int i=1;i<=30;i++){
        for(int j=1;j<=30;j++){
            if(i != 1){ //cut j len, for 1 to n
                ll cost = j*j;
                for(int k=1;k <= min(i*j, 50);k++){
                    for(int w=1;w<i;w++){ //local cut
                        for(int v=0;v<=k;v++){
                            dp[i][j][k] = min(dp[w][j][v] + cost + dp[i-w][j][k-v], dp[i][j][k]);
                        }
                    }
                }
            }
            if(j != 1){
                ll cost = i*i;
                for(int k=1;k <= min(i*j, 50);k++){
                    for(int w=1;w<j;w++){ //local cut
                        for(int v=0;v<=k;v++){
                            dp[i][j][k] = min(dp[i][w][v] + cost + dp[i][j-w][k-v], dp[i][j][k]);
                        }
                    }
                }
            }
        }
    }

}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    init();
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        cout << dp[n][m][k] << "\n";
    }
}
