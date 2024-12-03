#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
ll dp[N][N][2];
int req[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x;
    cin >> n >>  x;
    vector<int> alln = {0, x};
    vector<int> y(n), z(n);
    map<int,int> mpy;
    for(int i=0;i<n;i++){
        cin >> y[i];
        mpy[y[i]] = i;
        alln.push_back(y[i]);
    }
    for(int i=0;i<n;i++){
        cin >> z[i];
        alln.push_back(z[i]);
    }
    sort(alln.begin(), alln.end());
    int m = alln.size();
    memset(dp, 63, sizeof(dp));
    int dst = -1, src = -1;
    for(int i=0;i<m;i++){
        if(alln[i] == 0){
            dp[i][i][0] = dp[i][i][1] = 0;
            src = i;
        }
        if(alln[i] == x) dst = i;
        if(mpy.count(alln[i])){
            int zn = mpy[alln[i]];
            int vzn = z[zn];
            req[i] = lower_bound(alln.begin(), alln.end(), vzn) - alln.begin();
        }else req[i] = -1;
    }
    for(int d=1;d<=m-1;d++){
        for(int i=0;i+d<m;i++){
            int j = i + d;
            //[i, j]
            if(req[i] == -1 || (req[i] >= i+1 && req[i] <= j)){
                if(dp[i+1][j][0] < INF_LL){
                    dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][0] + abs(alln[i+1] - alln[i]));
                }
                if(dp[i+1][j][1] < INF_LL){
                    dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][1] + abs(alln[j] - alln[i]));
                }
            }   
            if(req[j] == -1 || (req[j] >= i && req[j] <= j-1)){
                if(dp[i][j-1][0] < INF_LL){
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + abs(alln[i] - alln[j]));
                }
                if(dp[i][j-1][1] < INF_LL){
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + abs(alln[j-1] - alln[j]));
                }
            }
        }
    }
    ll ans = INF_LL;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(i <= min(src,dst) && j >= max(src,dst)){
                ans = min(ans, dp[i][j][0]);
                ans = min(ans, dp[i][j][1]);
            }
        }
    }
    if(ans == INF_LL) ans = -1;
    cout << ans << "\n";
}
