#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
ll ce[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        for(int i=n;i>=1;i--){
            ll nx = n/i;
            ce[i] = (nx * (nx - 1))/2; 
            for(int j=2*i;j<=n;j+=i) ce[i] -= ce[j];
        }
        ll ans = m;
        for(int i=n;i>=2;i--){
            ll cur = ce[i] / (i - 1);
            if(cur > 0){
                ll su = m / (i-1);
                if(su <= cur){
                    ans += su;
                    m -= (i-1) * su;
                }else{
                    ans += cur;
                    m -= (i-1) * cur;
                }
            }
        }
        if(m == 0) cout << ans << "\n";
        else cout << "-1\n";
        // cout << mx << "\n";
    }
}
