#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-11; 
using namespace std;

double dp[50];
double calc(double qv){
    dp[0] = 1;
    for(int i=1;i<=50;i++) dp[i] = 0;
    for(int i=1;i<=50;i++){
        double p = 1.0 - i/qv;
        for(int j=50;j>0;j--){
            dp[j] = (dp[j] * (1-p)) + dp[j-1] * p;
        }
        dp[0] *= (1-p);
    }
    return dp[20];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    double lo = 50, hi = 1000;
    //if we do calc(50) ~ 4% and calc(1000) ~ 0%, we can argue it is decreasing.
    while(hi - lo > EPS){
        double mid = (lo + hi)/2;
        if(calc(mid) >= 0.02) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(10) << lo << "\n";
}
