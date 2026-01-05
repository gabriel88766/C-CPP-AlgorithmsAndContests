#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double dp[1 << 20];
double den[20];
double val[20];
ll tim[1 << 20];
ll d[20], p[20], c[20], lx[20], rx[20], ly[20], ry[20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int j=0;j<n;j++){
        cin >> d[j] >> p[j] >> c[j] >> lx[j] >> rx[j] >> ly[j] >> ry[j];
    }
    for(int j=0;j<n;j++){
        den[j] = 1.0 / (ry[j] - ly[j]);
        val[j] = (lx[j] + rx[j]) / 2.0;
    }
    double ans = 0;
    for(int j=1;j<(1 << n);j++){
        int b = (31 - __builtin_clz(j));        
        tim[j] = tim[j ^ (1 << b)] + c[b];
        for(int cb = 0; cb < n; cb++){
            if(!(j & (1 << cb))) continue;
            if(tim[j] > d[cb]) continue;
            double cch;
            if(tim[j] <= ly[cb]) cch = 1;
            else if(tim[j] <= ry[cb]){
                cch = (ry[cb] - tim[j]) * den[cb];
            }else cch = 0;
            dp[j] = max(dp[j], dp[j ^ (1 << cb)] + cch * val[cb] + p[cb]);
        }
        ans = max(ans, dp[j]);
    }
    cout << fixed << setprecision(10) << ans << "\n";
    
}
