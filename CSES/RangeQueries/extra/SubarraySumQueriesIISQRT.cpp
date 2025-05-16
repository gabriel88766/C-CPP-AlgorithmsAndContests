#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
const int M = 450; //sqrt(N)
ll mn[N/M + 1], mx[N/M + 1], ansb[N/M + 1];
ll val[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    memset(mn, 63, sizeof(mn));
    memset(mx, 192, sizeof(mx));
    mn[0] = mx[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> val[i];
        val[i] += val[i-1];
        mn[i/M] = min(mn[i/M], val[i]);
        mx[i/M] = max(mx[i/M], val[i]);
    }
    //calculate for each block.
    for(int b=0;b*M <= n; b++){
        ll cur = 0;
        ll mnc;
        mnc = (b == 0? 0 : val[b*M - 1]);
        for(int j=b*M; j<= min((b+1)*M - 1, n); j++){
            cur = max(cur, val[j] - mnc);
            mnc = min(mnc, val[j]);
        }
        ansb[b] = cur;
    }
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        ll mc = val[l-1];
        for(int b=l/M; b <= r/M; b++){
            if(b == l/M){
                for(int j=l;j<=min((b + 1)*M - 1, r); j++){
                    mc = min(mc, val[j]);
                    ans = max(ans, val[j] - mc);
                }
            }else if(b == r/M){
                for(int j=b*M;j<=r; j++){
                    mc = min(mc, val[j]);
                    ans = max(ans, val[j] - mc);
                }
            }else{
                ans = max(ans, ansb[b]);
                ans = max(ans, mx[b] - mc);
                mc = min(mc, mn[b]);
            }
        }
        cout << ans << "\n";
    }
}
