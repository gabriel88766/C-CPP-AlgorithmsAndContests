#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll n, k, ans;
ll dp[20][2][2][58][39][20][20];
ll pr[2][58][39][20][20];
ll p0[2];
ll p2[58];
ll p3[39];
ll p5[20];
ll p7[20];
vector<tuple<int, int, int, int, int>> st;
vector<tuple<int, int, int, int, int>> vx = {{1, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 2, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 1}, {0, 3, 0, 0, 0}, {0, 0, 2, 0, 0}};
void query(string ss) {
    int n = ss.size();
    //memset(dp, 0, sizeof(dp)); //if more than 1 query
    dp[n][0][0][0][0][0][0] = 1;
    dp[n][1][0][0][0][0][0] = 1;
 
    for(int i = n-1; i >=0 ; i--) {
        for(int d = 0; d <= ss[i] - '0' ; d++) { //10*k to avoid overflow and negatives.
            // if(i == 0 && d == 0) continue;
            auto [t, w, x, y, z] = vx[d];
            for(auto [tt, ww, xx, yy, zz] : st){
                if(tt >= t && ww >= w && xx >= x && yy >= y && zz >= z){
                    if(t == 1){
                        dp[i][1][1][ww][xx][yy][zz] += d == (ss[i] - '0') ? dp[i+1][1][1][ww-w][xx-x][yy-y][zz-z] + dp[i+1][1][0][ww-w][xx-x][yy-y][zz-z] : dp[i+1][0][1][ww-w][xx-x][yy-y][zz-z] + dp[i+1][0][0][ww-w][xx-x][yy-y][zz-z];
                        if(d != 0 && i == 0 && pr[tt][ww][xx][yy][zz] <= k) ans += d == (ss[i] - '0') ? dp[i+1][1][1][ww-w][xx-x][yy-y][zz-z] + dp[i+1][1][0][ww-w][xx-x][yy-y][zz-z] : dp[i+1][0][1][ww-w][xx-x][yy-y][zz-z] + dp[i+1][0][0][ww-w][xx-x][yy-y][zz-z];
                    }else{
                        dp[i][1][tt][ww][xx][yy][zz] += d == (ss[i] - '0') ? dp[i+1][1][tt][ww-w][xx-x][yy-y][zz-z] : dp[i+1][0][tt][ww-w][xx-x][yy-y][zz-z];
                        if(d != 0 && i == 0 && pr[tt][ww][xx][yy][zz] <= k) ans += d == (ss[i] - '0') ? dp[i+1][1][tt][ww-w][xx-x][yy-y][zz-z] : dp[i+1][0][tt][ww-w][xx-x][yy-y][zz-z]; 
                    }
                    
                    
                }
            }
        }
        for(int d = 0; d < 10 ; d++) {
            auto [t, w, x, y, z] = vx[d];
            for(auto [tt, ww, xx, yy, zz] : st){
                if(tt >= t && ww >= w && xx >= x && yy >= y && zz >= z){
                    if(t == 1){
                        dp[i][0][1][ww][xx][yy][zz] += dp[i+1][0][0][ww-w][xx-x][yy-y][zz-z] + dp[i+1][0][1][ww-w][xx-x][yy-y][zz-z];
                        if(i != 0 && d != 0 && pr[tt][ww][xx][yy][zz] <= k) ans +=  dp[i+1][0][0][ww-w][xx-x][yy-y][zz-z] + dp[i+1][0][1][ww-w][xx-x][yy-y][zz-z];
                    }else{
                        dp[i][0][tt][ww][xx][yy][zz] += dp[i+1][0][tt][ww-w][xx-x][yy-y][zz-z];
                        if(i != 0 && d != 0 && pr[tt][ww][xx][yy][zz] <= k) ans +=  dp[i+1][0][tt][ww-w][xx-x][yy-y][zz-z];
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
    //freopen("in", "r", stdin); //test input
    p2[0] = p3[0] = p5[0] = p7[0] = 1;
    p0[1] = 0;
    p0[0] = 1;
    for(int i=1;i<=19;i++){
        p7[i] = 7*p7[i-1];
        p5[i] = 5*p5[i-1];
    }
    for(int i=1;i<=38;i++){
        p3[i] = p3[i-1] * 3;
    }
    for(int i=1;i<=57;i++){
        p2[i] = p2[i-1] * 2;
    }
    for(int i=0;i<=57;i++){
        for(int j=0;j<=38;j++){
            if(p2[i] * p3[j] >= 1e18) break; 
            for(int k=0;k<=19;k++){
                if(p2[i] * p3[j] * p5[k] >= 1e18) break;
                for(int z=0;z<=19;z++){
                    if(p2[i] * p3[j] * p5[k] * p7[z] >= 1e18) break;
                    st.push_back({0, i, j, k, z});
                    st.push_back({1, i, j, k, z});
                    pr[0][i][j][k][z] = p2[i] * p3[j] * p5[k] * p7[z];
                }
            }
        }
    }
    
    cin >> n >> k;
    string s = to_string(n);
    query(s);
    
    cout << ans << "\n";
}
