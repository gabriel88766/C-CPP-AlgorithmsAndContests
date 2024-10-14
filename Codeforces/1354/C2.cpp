#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        double ang = 2*PI;
        ang /= (4*n);
        double x = 1.0/sin(ang);
        double ia = (2*PI)/(2*n);
        double lo = 0, hi = ia / 2;
        for(double jmp = hi/2;jmp>=EPS;jmp/=2){
            while(lo + jmp <= hi){
                double ti = lo + jmp;
                double l = x * cos(ti);
                double xi = (l - x*sin(ti))/2;
                double a1 = ia / 2 - ti;
                double rot = ia;
                bool ok = true;
                for(int j=0;j<n;j++){
                    xi += cos(a1);
                    a1 += rot;
                    if(xi >= l) ok = false;
                }
                if(ok) lo += jmp;
                else break;
            }
        }
         cout << fixed << setprecision(15) << x*cos(lo) << "\n";
        //h tg ang = l/2
        // cout << fixed << setprecision(15) << 1.0/tan(ang) << "\n";
        //l = 1/tg(ang)
    }
}
