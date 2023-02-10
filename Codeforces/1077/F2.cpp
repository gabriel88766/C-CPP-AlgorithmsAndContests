#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
ll dp[N][N];


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, x, k;
    cin >> n >> k >> x;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    if(n/k > x){
        cout << -1;
        return 0;
    }
    memset(dp, 192, sizeof(dp));
    dp[0][0] = 0;
    for(int j=1;j<=x;j++){
        //Max Queue.
        deque<pair<ll, int>> dq;
        for(int i=1;i<=n;i++){
            if(!dq.empty() && dq.front().second < (i-k)) dq.pop_front();
            while(!dq.empty() && dq.back().first <= dp[j-1][i-1]) dq.pop_back();
            dq.push_back({dp[j-1][i-1], i-1});
            dp[j][i] = dq.front().first + v[i];
        }
    }
    ll ans = 0;
    for(int i=n-k+1; i<=n;i++) ans = max(ans, dp[x][i]);
    cout << ans;
}
