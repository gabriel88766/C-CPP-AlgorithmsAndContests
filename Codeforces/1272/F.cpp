#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[205][205][205];
tuple<int,int,int> par[205][205][205];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 63, sizeof(dp));
    string s, t;
    cin >> s >> t;
    queue<tuple<int, int, int>> qp;
    qp.push({0, 0, 0});
    dp[0][0][0] = 0;
    while(qp.size()){
        auto [sz, i, j] = qp.front();
        qp.pop();
        if(sz > 200) continue;
        int ni, nj;
        if(i < s.size() && s[i] == '(') ni = i+1;
        else ni = i;
        if(j < t.size() && t[j] == '(') nj = j+1;
        else nj = j;
        if(dp[sz+1][ni][nj] > dp[sz][i][j] + 1){
            dp[sz+1][ni][nj] = dp[sz][i][j] + 1;
            par[sz+1][ni][nj] = {sz, i, j};
            qp.push({sz+1, ni, nj});
        }
        if(sz == 0) continue;
        if(i < s.size() && s[i] == ')') ni = i+1;
        else ni = i;
        if(j < t.size() && t[j] == ')') nj = j+1;
        else nj = j;
        if(dp[sz-1][ni][nj] > dp[sz][i][j] + 1){
            dp[sz-1][ni][nj] = dp[sz][i][j] + 1;
            par[sz-1][ni][nj] = {sz, i, j};
            qp.push({sz-1, ni, nj});
        }
    }
    string ans;
    int ux = 0, ui = s.size(), uj = t.size();
    while(ux != 0 || ui != 0 || uj != 0){
        auto [nx, ni, nj] = par[ux][ui][uj];
        if(nx == ux + 1){
            ans += ')';
        }else{
            ans += '(';
        }
        ux = nx, ui = ni, uj = nj;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";


}
