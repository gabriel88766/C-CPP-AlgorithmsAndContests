#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> cs[4];
vector<ll> ps[4];
int sz[4];
ll dp[300005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    //maximum weight = m;
    for(int i=0;i<n;i++){
        int w, c;
        cin >> w >> c;
        cs[w].push_back(c);
    }
    for(int i=1;i<=3;i++) {
        sort(cs[i].begin(), cs[i].end(), greater<ll>());
        sz[i] = cs[i].size();
        ps[i].resize(sz[i]+1);
        for(int j=1;j<=sz[i];j++){
            ps[i][j] = ps[i][j-1] + cs[i][j-1];
        }
    }
    for(int i = 1; i <= sz[1] + 2*sz[2]; i++){
        if(i % 2 && !sz[1]) continue;
        int lo = max((i-sz[1]+1)/2, 0), hi = min(i/2, sz[2]);
        while(lo < (hi - 3)){
            int m1 = lo + (hi - lo) / 3;
            int m2 = hi - (hi - lo) / 3;
            ll val1 = ps[2][m1] + ps[1][i-2*m1];
            ll val2 = ps[2][m2] + ps[1][i-2*m2];
            if(val1 >= val2) hi = m2;
            else lo = m1; 
        }
        for(int j=lo;j<=hi;j++){
            assert(i-2*j >= 0);
            assert(i-2*j <= sz[1]);
            dp[i] = max(dp[i], ps[2][j] + ps[1][i-2*j]);
        }
    }
    for(int i=0;i<= sz[1] + 2*sz[2]; i++){
        if(i > m) break;
        if(i % 2 && !sz[1]) continue;
        int qt3 = min(sz[3], (m-i)/3);
        dp[m] = max(dp[m], dp[i] + ps[3][qt3]);
    }
    cout << dp[m] << "\n";

}
