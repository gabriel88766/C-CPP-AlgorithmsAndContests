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
        int n, m;
        cin >> n >> m;
        vector<int> a(n+1), tm(m+1), pm(m+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<vector<tuple<int, int, int>>> pos(n+1);
        for(int i=1;i<=m;i++){
            int e, p;
            cin >> e >> tm[i] >> pm[i];
            pos[e].push_back({pm[i], tm[i], i});
        }
        vector<int> ans;
        int tt = 0;
        for(int i=1;i<=n;i++){
            vector<int> dp(201, INF_INT);
            vector<vector<pair<int, int>>> hist(201);
            // vector<pair<int, int>> par(201, make_pair(-1, -1));
            dp[0] = 0;
            for(auto [p, t, k] : pos[i]){
                for(int j=200;j>=p;j--){
                    if(dp[j] > dp[j-p] + t ){
                        dp[j] = dp[j-p] + t;
                        hist[j].push_back({dp[j], k});
                    }
                }
            }
            int mn = 100;
            for(int j=101;j<=200;j++) if(dp[j] < dp[mn]) mn = j;
            if(dp[mn] == INF_INT){
                tt = INF_INT;
                break;
            }else{
                tt += dp[mn];
                int cur = mn;
                int dpc = dp[mn];
                while(cur != 0){
                    for(auto [dpx, k] : hist[cur]){
                        if(dpx == dpc){
                            ans.push_back(k);
                            dpc -= tm[k];
                            cur -= pm[k];
                            break;
                        }
                    }
                }
            }
            if(tt > a[i]){
                tt = INF_INT;
                break;
            }
        }
        if(tt == INF_INT) cout << "-1\n";
        else{
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}
