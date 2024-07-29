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
        map<string, int> mp;
        vector<pair<int,int>> vp;
        int c = 0;
        for(int i=0;i<n;i++){
            string s, t;
            cin >> s >> t;
            if(!mp.count(s)) mp[s] = ++c;
            if(!mp.count(t)) mp[t] = ++c;
            vp.push_back({mp[s], mp[t]});
        }
        vector<vector<bool>> dp(1 << n, vector<bool>(n, false));
        for(int j=0;j<n;j++) dp[0][j] = true;
        for(int j=1;j<(1 << n);j++){
            for(int v=0;v<n;v++){
                if(j & (1 << v)){
                    int src = j ^ (1 << v);
                    for(int u=0;u<n;u++){
                        if(dp[src][u]){
                            if(vp[u].first == vp[v].first || vp[u].second == vp[v].second){
                                dp[j][v] = true;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int j=1;j<(1 << n);j++){
            for(int x=0;x<n;x++){
                if(dp[j][x]) ans = max(ans, __builtin_popcount(j));
            }
        }

        cout << n-ans << "\n";
    }
}
