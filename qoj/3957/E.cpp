#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-10; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        double d1, d2;
        cout << "? " << 1 << " " << 0 << "\n";
        cout.flush();
        cin >> d1;
        cout << "? " << 1 << " " << 1 << "\n";
        cout.flush();
        cin >> d2;
        double A = d1 / d2;

        double lo = 0, hi = PI / 4;
        while (hi - lo > EPS) {
            double mid = (lo + hi) / 2;
            double cur = cos(PI / 4 - mid) / cos(mid);
            if (cur < A)
                lo = mid;
            else
                hi = mid;
        }
        double h = d1 * cos(lo);
        ll area = lround(4 * h * h);

        cout << "! " << area << "\n";
        cout.flush();
    }
}
