#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
int dp[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    s = " " + s;
    vector<int> dif(n+1);
    for(int i=1;i<n;i++){
        if(s[i] != s[i+1]){
            dif[i] = 1;
        }else{
            dif[i] = 0;
        }
    }
    // 4 corner cases: choose 1 -> k and n-k+1 -> n
    int ans = 1;
    for(int i=0;i<4;i++){
        int cm = m - __builtin_popcount(i);
        if(cm < 0) continue;
        auto cdif = dif;
        if(i & 1) cdif[k] ^= 1; //if n just ignore...
        if(i & 2) cdif[n-k] ^= 1; //if 0 just ignore...
        vector<int> ad;
        for(int j=1;j<=k;j++){
            vector<int> cv;
            for(int u = j; u < n; u += k){
                cv.push_back(u);
            }
            if(cv.size() == 1) continue;
            vector<int> cvv;
            for(int u=0;u<cv.size();u++){
                if(cdif[cv[u]] == 0) cvv.push_back(u);
            }
            int mx = cvv.size() / 2;
            for(int x = 0; x <= cvv.size(); x++){
                for(int y = 0; y <= mx; y++){
                    dp[x][y] = INF_INT;
                }
            }
            dp[0][0] = 0;
            
            for(int x = 1; x <= cvv.size(); x++){
                for(int y = 0; y <= mx; y++) dp[x][y] = dp[x-1][y];
                if(x != 1){
                    for(int y = 1;y <= mx; y++){
                        dp[x][y] = min(dp[x][y], dp[x-2][y-1] + cvv[x-1] - cvv[x-2]);
                    }
                }
            }
            for(int y = 1; y <= mx; y++){
                ad.push_back(dp[cvv.size()][y] - dp[cvv.size()][y-1]);
            }
        }
        int cur = 1;
        for(int j=1; j<n;j++) cur += cdif[j];
        sort(ad.begin(), ad.end());
        for(int j=0;j<ad.size();j++){
            if(cm - ad[j] >= 0){
                cur += 2;
                cm -= ad[j];
            }else break;
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
