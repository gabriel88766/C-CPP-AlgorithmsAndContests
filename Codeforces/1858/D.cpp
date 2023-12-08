#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        s = " " + s;
        vector<int> ps(n+1, 0);
        for(int i=1;i<=n;i++){
            if(s[i] == '1') ps[i]++;
            ps[i] += ps[i-1];
        }
        auto func = [&](int l, int r){
            return ps[r] - ps[l-1];
        };
        vector<vector<int>> dp1(n+1, vector<int>(k+1));
        vector<vector<int>> dp2(n+1, vector<int>(k+1));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int qt = j-i+1 - func(i, j); //for max beginning in i and ending in j
                if(qt <= k){
                    dp1[i][qt] = max(dp1[i][qt], j-i+1);
                    dp2[j][qt] = max(dp2[j][qt], j-i+1);
                }
            }
        }
        //change to beginning after i and ending before i
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<=k;j++){
                dp1[i][j] = max(dp1[i][j], dp1[i+1][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp2[i][j] = max(dp2[i][j], dp2[i-1][j]);
            }
        }
        vector<int> maxl1(n+1, -INF_INT);
        for(int i=0;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                int x = func(j, j+i-1);
                if(x > k) continue;
                //from 1 to j-1 and from j+i to n, with k-x changes
                int qt = 0;
                if(j-1 >= 1) qt = max(qt, dp2[j-1][k-x]);
                if(j+i <= n) qt = max(qt, dp1[j+i][k-x]);
                maxl1[i] = max(maxl1[i], qt);
            }
        }
        for(int i=1;i<=n;i++){
            int ans = 0;
            for(int j=0;j<=n;j++){
                if(maxl1[j] != INF_INT){
                    ans = max(ans, i*j+maxl1[j]);
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
