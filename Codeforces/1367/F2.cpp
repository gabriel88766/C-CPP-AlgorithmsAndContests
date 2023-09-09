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
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        vector<int> aux(n);
        vector<set<int>> xx(n+1);
        int cnt = -1, cur = -1;
        for(int i=0;i<n;i++){
            if(v[i].first != cur){
                cur = v[i].first;
                ++cnt;
            }
            aux[v[i].second] = cnt;
            xx[cnt].insert(v[i].second);
        }
        vector<vector<int>> dp(3, vector<int>(n, 0));
        int best = 0;
        for(int i=0;i<n;i++) dp[0][i] = 1;
        for(int i=0;i<n;i++){
            int ord = aux[i];
            auto it = xx[ord].lower_bound(i+1);
            auto it2 = xx[ord+1].lower_bound(i);
            if(it != xx[ord].end()){
                dp[0][*it] = max(dp[0][*it], dp[0][i]+1);
                dp[1][*it] = max(dp[1][*it], dp[1][i]+1);
                dp[2][*it] = max(dp[2][*it], dp[2][i]+1);
            }
            if(it2 != xx[ord+1].end()){
                if(it2 == xx[ord+1].begin()){
                    dp[1][*it2] = max(dp[1][*it2], dp[0][i]+1); //from begin to mid;
                    if(it == xx[ord].end()){
                        dp[1][*it2] = max(dp[1][*it2], dp[1][i]+1); //from mid to mid;
                    }
                }else{
                    dp[2][*it2] = max(dp[2][*it2], dp[0][i]+1); //from begin to end
                    if(it == xx[ord].end()){
                        dp[2][*it2] = max(dp[2][*it2], dp[1][i]+1); //from mid to end
                    }
                }
            }

            best = max(best, dp[0][i]);
            best = max(best, dp[1][i]);
            best = max(best, dp[2][i]);
        }

        cout << n-best << "\n";
    }
}
