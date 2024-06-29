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
    ll x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll ans = abs(y2-y1);
    if(x2 >= x1){
        ll mm = abs(y2-y1);
        if((x1+y1) % 2 == 0) mm++;
        x1 = min(x2, x1 + mm);
        ans += (x2-x1+1)/2;
    }else{
        ll mm = abs(y2-y1);
        if((x1+y1) % 2 == 1) mm++;
        x1 = max(x2, x1 - mm);
        ans += (x1 - x2 + 1)/2;
    }
    cout << ans << "\n";
}
