#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 5005;
int v[N], val[N];
int dp[N];
 
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> v[i];
    sort(v+1, v+n+1);
    memset(dp, 192, sizeof(dp));
    dp[0] = 0;
    queue<pair<int,pair<int,int>>> upd;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((v[j] - v[i]) <= 5 && v[j] >= v[i]) val[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        while(!upd.empty() && (upd.front().first + 5) < v[i]){
            auto u = upd.front(); upd.pop();
            dp[u.second.first] = max(dp[u.second.first], u.second.second);
        }
        for(int j=1;j<=k;j++){
            if(dp[j-1] < 0) break;
            upd.push({v[i], {j, dp[j-1] + val[i]}});
        }
    }
    while(!upd.empty()){
        auto u = upd.front(); upd.pop();
        dp[u.second.first] = max(dp[u.second.first], u.second.second);
    }
    for(int i=1;i<=k;i++) dp[i] = max(dp[i], dp[i-1]);
    cout << dp[k];
}