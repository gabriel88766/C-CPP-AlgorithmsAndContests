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
        int maxx = -1500, minx = 1500;
        int maxy = -1500, miny = 1500;
        for(int i=0;i<4;i++){
            int x, y;
            cin >> x >> y;
            maxx = max(maxx, x);
            minx = min(minx, x);
            maxy = max(maxy, y);
            miny = min(miny, y);
        }
        cout << (maxx-minx)*(maxy - miny) << "\n";
    }
}
