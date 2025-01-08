#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
pair<int,int> dp[N][2];
int par[N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    dp[0][0] = dp[0][1] = {-1, 200'005};
    for(int i=1;i<=n;i++) dp[i][0] = dp[i][1] = {-1, -1};
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        //for increasing
        if(dp[i-1][0] != make_pair(-1, -1) && x > dp[i-1][0].first){
            dp[i][0] = {x, dp[i-1][0].second};
            par[i][0] = 0;
        }else if(dp[i-1][1] != make_pair(-1, -1) && x > dp[i-1][1].first){
            dp[i][0] = {x, dp[i-1][1].second};
            par[i][0] = 1;
        }
        //for decreasing
        if(dp[i-1][1] != make_pair(-1, -1) && x < dp[i-1][1].second){
            dp[i][1] = {dp[i-1][1].first, x};
            par[i][1] = 1;
        }else if(dp[i-1][0] != make_pair(-1, -1) && x < dp[i-1][0].second){
            dp[i][1] = {dp[i-1][0].first, x};
            par[i][1] = 0;
        }
    }
    pair<int,int> cur = {-1, -1};
    if(dp[n][0] != make_pair(-1, -1)){
        cur = {n, 0};
    }else if(dp[n][1] != make_pair(-1, -1)){
        cur = {n, 1};
    }
    if(cur != make_pair(-1, -1)){
        cout << "YES\n";
        vector<int> ans;
        while(cur.first != 0){
            ans.push_back(cur.second);
            cur.second = par[cur.first][cur.second];
            cur.first--;
        }
        reverse(ans.begin(), ans.end());
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }else cout << "NO\n";

}
