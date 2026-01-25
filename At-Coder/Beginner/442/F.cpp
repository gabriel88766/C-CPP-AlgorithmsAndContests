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
    int n;
    cin >> n;
    vector<string> vs(n+1);
    for(int i=1;i<=n;i++){
        cin >> vs[i];
        vs[i] = " " + vs[i];
    }
    vector<int> dp(n+1, 0);
    for(int i=1;i<=n;i++){
        vector<int> wr(n+2, 0), br(n+2, 0), mn(n+2, INF_INT);
        for(int j=1;j<=n;j++){
            wr[j] = wr[j-1];
            if(vs[i][j] != '.') wr[j]++;
        }
        for(int j=n;j>=1;j--){
            br[j] = br[j+1];
            if(vs[i][j] != '#') br[j]++;
        }
        for(int j=n;j>=0;j--){
            mn[j] = mn[j+1];
            mn[j] = min(mn[j], dp[j]);
        }
        for(int j=0;j<=n;j++){
            dp[j] = wr[j] + br[j+1] + mn[j];
        }
    }
    cout << *min_element(dp.begin(), dp.end()) << "\n";
}
