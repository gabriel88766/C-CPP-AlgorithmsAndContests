#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
int gr[N][N];
int cur[3][N];
bool ok[N][8];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(gr, 0xFF, sizeof(gr)); 
    int h, w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=0;j<8;j++){
            int x = j & 1;
            int y = (j & 2) >> 1;
            int z = (j & 4) >> 2;
            for(int k=0;k<=w+1;k++){
                cur[0][k] = gr[i-1][k] ^ z;
                cur[1][k] = gr[i][k] ^ y;
                cur[2][k] = gr[i+1][k] ^ x;
            }
            ok[i][j] = true;
            for(int k=1;k<=w;k++){
                if(cur[1][k] != cur[1][k-1] && cur[1][k] != cur[1][k+1] && cur[1][k] != cur[0][k] && cur[1][k] != cur[2][k]){
                    ok[i][j] = false;
                }
            }
        }
    }
    vector<int> dp(8, 0);
    for(int j=0;j<8;j++) dp[j] = __builtin_popcount(j);
    for(int i=1;i<=h;i++){
        vector<int> ndp(8, INF_INT);
        for(int j=0;j<8;j++){
            if(dp[j] != INF_INT){
                int ns = j & 3;
                ns *= 2;
                if(ok[i][ns]) ndp[ns] = min(ndp[ns], dp[j]);
                if(ok[i][ns | 1]) ndp[ns | 1] = min(ndp[ns | 1], dp[j] + 1);
            }
        }
        dp = ndp;
    }
    
    if(*min_element(dp.begin(), dp.end()) != INF_INT) cout << *min_element(dp.begin(), dp.end()) << "\n";
    else cout << "-1\n";

}
