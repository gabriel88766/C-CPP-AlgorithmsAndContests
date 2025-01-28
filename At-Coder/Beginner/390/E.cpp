#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<pair<int, int>> vp[4];
int dp[4][5005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x;
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        vp[x].push_back({y, z});
    }
    vector<vector<int>> dp(4, vector<int>(x+2, 0));
    for(int i=1;i<=3;i++){
        dp[i][x+1] = INF_INT;
        for(auto &[a, b] : vp[i]){
            for(int j=x;j>=b;j--){
                dp[i][j] = max(dp[i][j], dp[i][j-b] + a);
            }
        }
    }
    int lo = 0, hi = 1e9;
    while(lo != hi){
        int mid = lo + (hi - lo + 1)/2;
        int id1 = lower_bound(dp[1].begin(), dp[1].end(), mid) - dp[1].begin();
        int id2 = lower_bound(dp[2].begin(), dp[2].end(), mid) - dp[2].begin();
        int id3 = lower_bound(dp[3].begin(), dp[3].end(), mid) - dp[3].begin();
        if(id1 + id2 + id3 <= x) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}
