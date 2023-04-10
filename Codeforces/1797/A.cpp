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
        int n, m;
        cin >> n >> m;
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 4;
        if(x1 == 1 && y1 == 1 || x1 == n && y1 == m || x1 == 1 && y1 == m || x1 == n && y1 == 1) ans = 2;
        if(x2 == 1 && y2 == 1 || x2 == n && y2 == m || x2 == 1 && y2 == m || x2 == n && y2 == 1) ans = 2;
        if(x1 == 1 || y1 == 1 || x1 == n || y1 == m) ans = min(ans, 3);
        if(x2 == 1 || y2 == 1 || x2 == n || y2 == m) ans = min(ans, 3);
        cout << ans << "\n";
    }
}
