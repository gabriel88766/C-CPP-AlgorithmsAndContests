#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


double harm(ll n){
    if(n == 0) return 0;
    if(n <= 10000){
        double ans = 0;
        for(int i=1;i<=n;i++){
            double cur = 1;
            cur /= i;
            ans += cur;
        }
        return ans;
    }else{
        double inv = 1.0/n;
        double ans = log(n) + 0.577215664901532860 + (1.0/2*inv)- (1.0/12 * inv*inv) + (1.0/120 * inv * inv * inv * inv);
        return ans;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        ll n, p;
        cin >> n >> p;
        ll mn = -1;
        double ans = 0;
        if(p != 0){
            double minv = 10000000;
            for(int j=2;;j++){
                if((j-1)*p > 100){
                    minv = min(minv, (double)j);
                    break;
                }else{
                    double cur = (j-1) * p;
                    cur /= 100;
                    cur = 1/cur;
                    cur *= j;
                    minv = min(minv, cur);
                }
            }
            cout << minv << " ";
            ll lo = 0, hi = n;
            while(lo != hi){
                ll mid = lo + (hi - lo)/2;
                assert(mid != n);
                double cur = n;
                cur /= n - mid;
                if(cur < minv) lo = mid + 1;
                else hi = mid;
            }
            mn = lo;
            ans = (n - mn) * minv;
        }else{
            mn = n;//from 1 to n, optimal is pay 1
        }
        ans += n * (harm(n) - harm(n-mn));
        cout << "Case #" << i << ": ";
        cout << setprecision(15) << ans << "\n";
    }
}
