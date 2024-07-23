#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e6+1;
ll cd[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll m, n, ans = 0;
        cin >> n >> m;
        vector<vector<ll>> div(m+1);
        for(ll d=1;d<=m;d++){
            for(ll g=d;g<=m;g+=d){
                //x1+x2 == d, d|g
                //gcd(x1,x2) = 1
                //gx1 = a, gx2 = b
                ll mxx2 = m/g;
                ll mnx1 = max(d - mxx2, 1LL);
                for(ll x1=mnx1;g*x1<=n && x1 < d;x1++){
                    if(gcd(x1, d-x1) == 1) ans++;
                }
                
            }
        }
        cout << ans << "\n";
        }
}
