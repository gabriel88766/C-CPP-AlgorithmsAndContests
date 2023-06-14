#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 100000;
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
        int xmin=-INF_INT, xmax=INF_INT, ymin=-INF_INT, ymax=INF_INT;
        for(int i=0;i<n;i++){
            int x, y, xp, xm, yp, ym;
            cin >> x >> y >> xm >> yp >> xp >> ym;
            if(xp == 0) xmax = min(xmax, x);
            if(xm == 0) xmin = max(xmin, x);
            if(yp == 0) ymax = min(ymax, y);
            if(ym == 0) ymin = max(ymin, y);
        }
        if(xmax < xmin || ymax < ymin) cout << "0\n";
        else cout << "1 " << xmax << " " << ymax << "\n";
    }
}
