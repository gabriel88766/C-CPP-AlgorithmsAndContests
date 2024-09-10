#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dps[22][2][1024];
ll dpq[22][2][1024];

ll query(string ss, int k) {
    int n = ss.size();
    memset(dps, 0, sizeof(dps)); //if more than 1 query
    memset(dpq, 0, sizeof(dpq));
    //empty suffixes having sum=0
    dpq[n][0][0] = 1;
    dpq[n][1][0] = 1;
    ll pcur = 1;
    for(int i = n-1; i >=0 ; i--) {
        for(int msk = 0; msk < (1 << 10) ; msk++) {
            for(int d = 0; d <= ss[i] - '0' ; d++) { //10*k to avoid overflow and negatives.
                int b = 1 << d;
                ll aux = (pcur * d) % MOD;
                dps[i][1][msk | b] += (d == ss[i]-'0') ? dps[i+1][1][msk] + dpq[i+1][1][msk] * aux : dps[i+1][0][msk] + dpq[i+1][0][msk] * aux;
                dps[i][1][msk | b] %= MOD;
                dpq[i][1][msk | b] += (d == ss[i]-'0') ? dpq[i+1][1][msk] : dpq[i+1][0][msk];
                dpq[i][1][msk | b] %= MOD;
            }
            for(int d = 0; d < 10 ; d++) {
                int b = 1 << d;
                ll aux = (pcur * d) % MOD;
                dps[i][0][msk | b] += dps[i+1][0][msk] + dpq[i+1][0][msk] * aux;
                dps[i][0][msk | b] %= MOD;
                dpq[i][0][msk | b] += dpq[i+1][0][msk];
                dpq[i][0][msk | b] %= MOD;
            }
        }
        pcur = (10 * pcur) % MOD;
    }
    ll ans = 0;
    //sum all above k
    for(int i=0;i<1024;i++){
        if(__builtin_popcount(i) <= k) ans = (ans + dps[0][1][i]) % MOD;
    }
    //remove all equal k-1 and i >= 1;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<1024;j++){
            if(__builtin_popcount(j) == k && (!(j & 1)))  ans = (ans + dps[i][0][j] + MOD) % MOD;
        }
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //cout << query(to_string(21), 2);
    ll l, r, k;
    cin >> l >> r >> k;
    ll a1 = query(to_string(r), k);
    ll a2 = query(to_string(l-1), k);
    ll ans = (a1 - a2) % MOD;
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}
