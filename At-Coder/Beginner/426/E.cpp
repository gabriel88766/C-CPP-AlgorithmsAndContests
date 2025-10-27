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
        int tsx, tsy, tgx, tgy, asx, asy, agx, agy;
        cin >> tsx >> tsy >> tgx >> tgy >> asx >> asy >> agx >> agy;
        double d1 = sqrt(pow(tgx - tsx, 2)+ pow(tgy - tsy, 2));
        double d2 = sqrt(pow(agx - asx, 2) + pow(agy - asy, 2));
        //ternary begin, ternary end
        double t1 = min(d1, d2);
        auto calc = [&](double tx){
            double ctx, cty, cax, cay;
            if(tx <= d1){
                ctx = tsx + tx/d1 * (tgx - tsx);
                cty = tsy + tx/d1 * (tgy - tsy);
            }else ctx = tgx, cty = tgy;
            if(tx <= d2){
                cax = asx + tx/d2 * (agx - asx);
                cay = asy + tx/d2 * (agy - asy);
            }else cax = agx, cay = agy;
            return sqrt(pow(cax - ctx, 2) + pow(cay - cty, 2));
        };


        double lo = 0, hi = t1;
        double ans = 1e60;
        while(hi - lo >= EPS){
            double m1 = lo + (hi - lo)/3;
            double m2 = lo + ((hi - lo)/3) * 2;
            if(calc(m1) < calc(m2)) hi = m2;
            else lo = m1;
        }
        ans = min(ans, calc(lo));
        lo = t1, hi = max(d1, d2);
        while(hi - lo >= EPS) {
            double m1 = lo + (hi - lo)/3;
            double m2 = lo + ((hi - lo)/3) * 2;
            if(calc(m1) < calc(m2)) hi = m2;
            else lo = m1;
        }
        ans = min(ans, calc(lo));
        cout << setprecision(15) << fixed << ans << "\n";
    }
}
