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
        int x1,y1,x2,y2,x3,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int dif1 = x2-x1, dif2 = x3-x1;
        int ans = 0;
        if(dif1 > 0 && dif2 > 0) ans += min(dif1, dif2);
        if(dif1 < 0 && dif2 < 0) ans += min(-dif1, -dif2);
        dif1 = y2-y1, dif2 = y3-y1;
        if(dif1 > 0 && dif2 > 0) ans += min(dif1, dif2);
        if(dif1 < 0 && dif2 < 0) ans += min(-dif1, -dif2);
        cout << ans+1 << "\n";
    }
}
