#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
int dp[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> p(n*k+1);
    for(int i=1;i<=n*k;i++) cin >> p[i];
    vector<bool> vis(n*k+1);
    int ans = 0;
    for(int i=1;i<=n*k;i++){
        if(!vis[i]){
            if(p[i] == i){
                vis[i] = true;
                continue;
            }
            int cur = i;
            vector<int> cv;
            cv.push_back(cur);
            cur = p[cur];
            while(cur != i){
                cv.push_back(cur);
                cur = p[cur];
            }
            vector<int> cnt(n);
            for(auto x : cv){
                cnt[x % n]++;
            }
            int x = cv.size();
            for(int j=0;j<x;j++){
                for(int k=0;k<x;k++){
                    dp[j][k] = 0;
                }
            }
            vector<vector<int>> vxx(n);
            for(int i=0;i<cv.size();i++) vxx[cv[i]%n].push_back(i);
            for(int k=2;k<=x;k++){
                for(int j=0;j<x;j++){
                    int l = j, r = j + k - 1;
                    if(r >= x) break;
                    if(cv[l] % n == cv[r] % n){
                        dp[l][r] = max(dp[l][r-1], dp[l+1][r]) + 1;
                    }else dp[l][r] = max(dp[l][r-1], dp[l+1][r]);
                    
                    for(auto x : vxx[cv[r] % n]){
                        if(x >= l && x < r) dp[l][r] = max(dp[l][r], dp[l][x-1] + dp[x][r]);
                    }

                }
            }
            ans += dp[0][x-1];

            for(auto x : cv) vis[x] = true;
        }
    }
    cout << ans << "\n";
}
