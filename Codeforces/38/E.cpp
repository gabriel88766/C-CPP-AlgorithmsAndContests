#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
ll dp[N][2];
ll ps[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<ll,ll>> mb;
    for(int i=0;i<n;i++){
        ll a, c;
        cin >> a >> c;
        mb.push_back({a,c}); 
    }
    ps[0] = 0;
    sort(mb.begin(), mb.end());
    for(int i=1;i<n;i++) ps[i] = ps[i-1] + mb[i].first;

    memset(dp, 63, sizeof(dp));
    dp[0][1] = mb[0].second;

    for(int i=1;i<n;i++){
        dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + mb[i].second;
        for(int j=0;j<i;j++){
            dp[i][0] = min(dp[i][0], dp[j][1] + ps[i]-ps[j]-(i-j)*mb[j].first);
        }
    }
    cout << min(dp[n-1][0], dp[n-1][1]);
}
