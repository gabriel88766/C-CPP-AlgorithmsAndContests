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
    ll A, B;
    cin >> A >> B;
    long double lo = 0, hi = 1e12;
    while(hi - lo > 1e-3){
        long double m1 = lo + (hi - lo)/3;
        long double m2 = lo + ((hi - lo)*2)/3;
        long double val1 = B * m1 + A / sqrtl(1+m1);
        long double val2 = B * m2 + A / sqrtl(1+m2);
        if(val1 < val2) hi = m2;
        else lo = m1;
    }
    ll x1 = lo;
    ll x2 = lo + 1;
    long double val1 = B * x1 + A / sqrtl(1 + x1);
    long double val2 = B * x2 + A / sqrtl(1 + x2);
    cout << fixed << setprecision(10) << min(val1, val2) << "\n";
}
