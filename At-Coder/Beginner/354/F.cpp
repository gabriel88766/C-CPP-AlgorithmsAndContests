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
        int n;
        cin >> n;
        vector<int> dp(n + 1, INF_INT);
        vector<int> gl(n+1), gr(n+1);
        vector<int> v(n+1);
        int mx = 0;
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            int ind = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
            gl[i] = ind;
            mx = max(mx, ind);
            dp[ind] = v[i];
        }
        //now longest decreasing
        fill(dp.begin(), dp.end(), INF_INT);
        dp[0] = -INF_INT;
        for(int i=n;i>=1;i--){
            int cur = -v[i];
            auto ind = lower_bound(dp.begin(), dp.end(), cur) - dp.begin();
            gr[i] = ind;
            dp[ind] = cur;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(gr[i] + gl[i] == mx + 1) ans.push_back(i);
        }
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
