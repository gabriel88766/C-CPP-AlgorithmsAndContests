#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
int c[N], a[N], dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<int> path = {0};
    int n;
    cin >> n;
    for(int i=1;i<n;i++) cin >> c[i];
    for(int i=1;i<n;i++){
        cin >> a[i];
        if(a[i] == 1) path.push_back(i);
    }
    int ans = 0;
    while(path.back() != 0){
        int u = path.back();
        path.pop_back();
        int v = path.back();
        memset(dp, 63, sizeof(dp));
        dp[u] = 0;
        for(int i=u;i>v;i--){
            for(int j=i-c[i]; j<= i-1; j++){
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        ans += dp[v];
    }
    cout << ans << "\n";
}
