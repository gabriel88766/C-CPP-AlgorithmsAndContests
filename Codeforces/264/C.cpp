#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5 + 1;
ll dp[N], v[N], c[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<=q;i++){
        ll a, b;
        cin >> a >> b;
        memset(dp, 192, sizeof(dp));
        dp[0] = 0;
        pair<ll, ll> m1 = {0, 0}, m2 = {0, 0}; //maximum 1 and maximum 2
        for(int i=1;i<=n;i++){
            ll mx1 = dp[c[i]];
            ll mx2 = (m1.second == c[i] ? m2.first : m1.first);
            ll mxp = max(mx1 + v[i] * a, mx2 + v[i] * b);
            if(mxp > dp[c[i]]) dp[c[i]] = mxp;
            if(mxp > m1.first){
                if(m1.second == c[i]){
                    m1.first = mxp;
                }else{
                    m2 = m1;
                    m1 = {mxp, c[i]};
                }
            }else if(mxp > m2.first && c[i] != m1.second){
                m2 = {mxp, c[i]};
            }
        }
        cout << m1.first << "\n";
    }
}
