#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> dp(505, vector<int>(505, INF_INT));
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m+1);
    dp[0][0] = -1;
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }
    int ans = 0;
    vector<pair<int,int>> ca[505];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=min(n,m);k++){
                dp[j][k] = min(dp[j][k], dp[j-1][k]);
            }
            if(a[i] == b[j]){
                auto it = lower_bound(dp[j-1].begin(), dp[j-1].end(), a[i]);
                int ind = it - dp[j-1].begin();
                ans = max(ans, ind);
                ca[ind].push_back({i, j});
                dp[j][ind] = min(dp[j][ind], a[i]);
            }
        }
    }   
    cout << ans << "\n";
    vector<int> pans;
    pair<int,int> cur = {n+1, m+1};
    int fc = ans;
    int val = INF_INT;
    while(fc){
        for(auto [aa, bb] : ca[fc]){
            if(aa < cur.first && bb < cur.second && a[aa] < val){
                val = a[aa];
                cur = {aa, bb};
                fc--;
                pans.push_back(val);
            }
        }
    }
    reverse(pans.begin(), pans.end());
    for(auto x : pans) cout << x << " ";
    cout << "\n";
}
