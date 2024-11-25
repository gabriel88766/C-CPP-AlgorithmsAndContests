#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1 << 20;
int dp[N];
vector<int> pos[21];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 63, sizeof(dp));
    int n;
    cin >> n;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    int ans = 0;
    for(int i=0;i<(1 << 20);i++){
        if(dp[i] != INF_INT) ans = max(ans, 2*__builtin_popcount(i));
        else continue;
        for(int j=0;j<20;j++){
            if(i & (1 << j)) continue;
            auto it = lower_bound(pos[j+1].begin(), pos[j+1].end(), dp[i]);
            if(it != pos[j+1].end()) it = next(it);
            if(it != pos[j+1].end()){
                dp[i | (1 << j)] = min(dp[i | (1 << j)], *it);
            }
        }
    }
    cout << ans << "\n";
}
