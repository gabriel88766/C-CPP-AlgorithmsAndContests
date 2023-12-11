#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ll dp[200005][3][3];
pair<ll,ll> p[200005][3][3];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<=n;k++){
                    dp[k][i][j] = -INF_LL;
                }
            }
        }
        dp[0][0][1] = 0;
        vector<vector<ll>> v(3, vector<ll>(n+1));
        for(int i=1;i<=n;i++) cin >> v[0][i];
        for(int i=1;i<=n;i++) cin >> v[1][i];
        for(int i=1;i<=n;i++) cin >> v[2][i];
        ll a1 = 0; //everything is equal
        for(int i=1;i<=n;i++) a1 += v[1][i];

        for(int i=1;i<=n;i++){
            dp[i][0][1] = dp[i-1][0][1] + v[1][i];
            p[i][0][1] = {0, 1};
            dp[i][1][2] = dp[i-1][0][1] + v[2][i];
            p[i][1][2] = {0, 1};
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    ll cur = dp[i-1][1][k] + v[j][i];
                    if(cur > dp[i][1][j]){
                        dp[i][1][j] = cur;
                        p[i][1][j] = {1, k};
                    }
                }
            }
            for(int j=0;j<3;j++){
                ll cur = dp[i-1][1][j] + v[0][i];
                if(cur > dp[i][2][0]){
                    dp[i][2][0] = cur;
                    p[i][2][0] = {1, j};
                }
            }
            for(int j=0;j<2;j++){
                ll cur = dp[i-1][2][j] + v[1][i];
                if(cur > dp[i][2][1]){
                    dp[i][2][1] = cur;
                    p[i][2][1] = {2, j};
                }
            }
        }
        ll a2 = max(dp[n][2][1], dp[n][2][0]);
        if(a1 >= a2){
            for(int i=1;i<=n;i++) cout << i << " ";
            cout << "\n";
        }else{
            vector<ll> ans(n+1);
            vector<int> ord;
            pair<ll,ll> beg = a2 == dp[n][2][1] ? make_pair(2, 1) : make_pair(2, 0);
            for(int i=n;i>=1;i--){
                ord.push_back(beg.second);
                beg = p[i][beg.first][beg.second];
            }
            ord.push_back(-1);
            reverse(ord.begin(), ord.end());
            vector<int> gr, ls, all;
            for(int i=1;i<=n;i++){
                if(ord[i] == 1) ans[i] = i;
                else if(ord[i] == 2) gr.push_back(i);
                else ls.push_back(i);
                if(ord[i] != 1) all.push_back(i);
            }
            reverse(gr.begin(), gr.end());
            reverse(ls.begin(), ls.end());
            for(auto x : gr){
                ans[x] = all.back();
                all.pop_back();
            }
            for(auto x : ls){
                ans[x] = all.back();
                all.pop_back();
            }
            for(int i=1;i<=n;i++) cout << ans[i] << " ";
            cout << "\n";
        }
    }
}