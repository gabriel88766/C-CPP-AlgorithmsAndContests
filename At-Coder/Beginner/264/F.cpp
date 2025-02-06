#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
ll dp[N][N][4];
ll solve(vector<vector<char>> &gr, vector<int> &r, vector<int> &c){
    memset(dp, 63, sizeof(dp));
    int n = gr.size(), m = gr[0].size();
    dp[0][0][0] = 0;
    dp[0][0][1] = r[0];
    dp[0][0][2] = c[0];
    dp[0][0][3] = r[0] + c[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<=3;k++){
                if(i != 0){
                    int lv = gr[i-1][j];
                    if(k == 1 || k == 2) lv ^= 1;
                    int nv = gr[i][j];
                    int nk = 0;
                    //if collumn is selected, keep
                    if(k & 2) nv ^= 1, nk ^= 2;
                    if(nv == lv) dp[i][j][nk] = min(dp[i][j][nk], dp[i-1][j][k]);
                    else {
                        nk ^= 1;
                        dp[i][j][nk] = min(dp[i][j][nk], dp[i-1][j][k] + r[i]);
                    }
                }
                if(j != 0){
                    int lv = gr[i][j-1];
                    if(k == 1 || k == 2) lv ^= 1;
                    int nv = gr[i][j];
                    int nk = 0;
                    //if row is selected, keep
                    if(k & 1) nk ^= 1, nv ^= 1;
                    if(nv == lv) dp[i][j][nk] = min(dp[i][j][nk], dp[i][j-1][k]);
                    else{
                        nk ^= 2;
                        dp[i][j][nk] = min(dp[i][j][nk], dp[i][j-1][k] + c[j]);
                    }
                }
            }
        }   
    }
    return min({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2], dp[n-1][m-1][3]});
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    vector<int> r(h), c(w);
    for(int i=0;i<h;i++) cin >> r[i];
    for(int j=0;j<w;j++) cin >> c[j];
    vector<vector<char>> gr(h, vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> gr[i][j];
            gr[i][j] -= '0';
        }
    }
    cout << solve(gr, r, c) << "\n";
}
