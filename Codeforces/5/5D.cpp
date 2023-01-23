#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    double a,v,l,d,w;
    cin >> a >> v; //accel and maxspeed
    cin >>  l >> d >> w; //leng, d of traffic sign, w of ts
    //w^2 > 2 * a * d?
    double ans = 0;
    if((w*w +EPS) > 2*a*d){
        if((v*v+EPS) > 2*a*l) ans = sqrt(2*l/a);
        else{
            double l1 = (v*v)/(2*a);
            double l2 = l-l1;
            ans = l2/v + sqrt(2*l1/a);
        }
    }else{
        if(v < (w+EPS)){
            double l1 = (v*v)/(2*a);
            double l2 = l-l1;
            ans = l2/v + sqrt(2*l1/a);
        }else{
            double hi = d, lo = 0, mid, vmax;
            while((hi-lo) > 1e-12){
                mid = (lo+hi)/2;
                vmax = sqrt(2*a*mid);
                double vts = sqrt(vmax*vmax-2*a*(d-mid));
                if(vts > w) hi = mid;
                else lo = mid;
            }
            if(vmax < v){
                ans = vmax/a + (vmax - w)/a;
                if((v*v+EPS) > (w*w+2*a*(l-d))) ans += (sqrt(w*w+2*a*(l-d))-w)/a;
                else{
                    double l1 = (v*v - w*w)/(2*a) + d;
                    double l2 = l-l1;
                    ans += l2/v + (v-w)/a;
                }
            }else{
                double l1 = (v*v)/(2*a), l2;
                l2 = d - (v*v - w*w)/(2*a);
                ans = v/a + (l2-l1)/v + (v-w)/a;
                l1 = (v*v-w*w) / (2*a) + d;
                if(l1 > l){
                    double vm = sqrt(w*w + 2*a*(l-d));
                    ans += (vm-w)/a;
                }else{
                    ans += (v-w)/a + (l-l1)/v;
                }


            }
            

        }
    }
    cout << setprecision(15) << fixed << ans;
}
