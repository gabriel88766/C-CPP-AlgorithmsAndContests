#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-11; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    double ans = 0;
    for(ll k=1;k<=100000;k++){
        //(a + 1/k)² + (b + 1/k)² <= (1 + 1/2k)² circle1
        //(a + 1/k)² + (b + 1/k)² >= (1 - 1/2k)² circle2
        double s1 = 0, s2 = 0;
        //s1 is calculated almost the same way as s2
        double i1 = sqrt(pow(1 + 0.5/k, 2) - pow(1.0/k, 2)) - 1.0/k;
        double i2 = sqrt(pow(1 - 0.5/k, 2) - pow(1.0/k, 2)) - 1.0/k;
        double r1 = 1 + 0.5/k;
        double r2 = 1 - 0.5/k;
        if(i1 >= 0){
            double a1 = acos((2*(r1*r1) - 2 * i1 * i1)/(2*r1*r1));
            s1 = a1/2 * r1 * r1;
            s1 -= r1*r1*sin(a1)/2;
            s1 += i1*i1/2;
        }
        if(i2 >= 0){
            double a2 = acos((2*(r2*r2) - 2 * i2 * i2)/(2*r2*r2));
            s2 = a2/2 * r2 * r2;
            s2 -= r2*r2*sin(a2)/2;
            s2 += i2*i2/2;
        }
        ans += (s1 - s2) * k;
    }
    cout << fixed << setprecision(5) << ans << "\n";
}
