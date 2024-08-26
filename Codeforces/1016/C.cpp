#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+2;
ll pr[N][2], su[N][2], v[N][2];
ll pr2[N][2], su2[N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i][0];
    for(int i=1;i<=n;i++) cin >> v[i][1];
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            pr[i][j] = pr[i-1][j];
            pr[i][j] += v[i][j];
            pr2[i][j] = pr2[i-1][j];
            pr2[i][j] += i*v[i][j];
        }
    }
     for(int i=n;i>=1;i--){
        for(int j=0;j<2;j++){
            su[i][j] = su[i+1][j];
            su[i][j] += v[i][j];
            su2[i][j] = su2[i+1][j];
            su2[i][j] += v[i][j] * (n-i+1);
        }
    }
    ll ans = 0;
    ll cur = 0;
    for(int i=1;i<=n;i++){
        //i'm up if i%2
        ll curs = cur;
        ll nm = (i-1)*2;
        ll f1 = nm - i;
        curs += (pr2[n][(i%2)^1] - pr2[i-1][(i%2)^1]) + f1 * (pr[n][(i%2)^1] - pr[i-1][(i%2)^1]);
        ll nm2 = nm + (n-i+1);
        f1 = nm2 - 1;
        curs += (su2[i][(i%2)]) + f1 * (su[i][(i%2)]);
        ans = max(ans, curs);
        cur += nm * v[i][(i%2)^1] + (nm+1)*v[i][i%2];
    }   
    cout << ans << "\n";
}
