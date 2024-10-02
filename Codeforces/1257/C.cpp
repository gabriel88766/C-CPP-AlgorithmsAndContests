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
        vector<vector<int>> oc(n+1);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            oc[x].push_back(i);
        }
        int ans = INF_INT;
        for(int i=1;i<=n;i++){
            if(oc[i].size() >= 2){
                for(int j=1;j<oc[i].size();j++){
                    ans = min(ans, oc[i][j] - oc[i][j-1] + 1);
                }
            }
        }
        if(ans == INF_INT) cout << "-1\n";
        else cout << ans << "\n";
    }
}
