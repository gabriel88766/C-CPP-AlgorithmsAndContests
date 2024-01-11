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
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        bool ok = false;
        int d1 = abs(sy - 1);
        int d2 = abs(n - sx);
        if(d1 > d && d2 > d) ok = true;
        d1 = abs(sx - 1);
        d2 = abs(m - sy);
        if(d1 > d && d2 > d) ok = true;
        if(ok) cout << n+m-2 << "\n";
        else cout << "-1\n";
    }
}
