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
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll d = (x1-x2)*(x1-x2) + (y1-y2) * (y1-y2);
        ll dR = r1 + r2;
        dR *= dR;
        if(d <= dR){
            //inside or not.
            //check if d + rmin < rmax => d² <= rmax² + rmin² - 2*rmax*rmin;
            ll rmx = max(r1, r2), rmn = min(r1, r2);
            if(d < rmx*rmx + rmn*rmn - 2*rmx*rmn) cout << "No\n";
            else cout << "Yes\n";
        }else cout << "No\n";
    }
}
