#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<pair<int,int>> qr[N];
int v[N];
int dp[N], ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    memset(dp, 63, sizeof(dp));
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=q;i++){
        int x, y;
        cin >> x >> y;
        qr[x].push_back({y, i});
    }
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        auto it = lower_bound(dp, dp+N, v[i]);
        *it = v[i];
        for(auto &[a, j] : qr[i]){
            ans[j] = prev(upper_bound(dp, dp+N, a)) - dp;
        }
    }
    for(int i=1;i<=q;i++){
        cout << ans[i] << "\n";
    }
}
