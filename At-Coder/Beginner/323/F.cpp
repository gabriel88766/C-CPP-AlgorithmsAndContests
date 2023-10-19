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
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll x4, y4, x5, y5;
    ll ans;
    if(x2 == x3 || y2 == y3){
        ans = abs(x3-x2) + abs(y3-y2);
        if(x2 == x3){
            if(y3 > y2) x4 = x2, y4 = y2-1;
            else x4 = x2, y4 = y2+1;
        }else{
            if(x3 > x2) x4 = x2-1, y4 = y2;
            else x4 = x2+1, y4 = y2;
        }
        ans += abs(x4-x1) + abs(y4-y1);
        if(y1 == y4 && y2 == y1 && x2 > min(x1, x4) && x2 < max(x1, x4)) ans += 2;
        if(x1 == x4 && x2 == x1 && y2 > min(y1, y4) && y2 < max(y1, y4)) ans += 2;
    }else{
        ans = abs(x2-x3) + abs(y2-y3) + 2;
        if(x3 > x2) x4 = x2-1, y4 = y2;
        else x4 = x2 + 1, y4 = y2;
        if(y3 > y2) x5 = x2, y5 = y2-1;
        else x5 = x2, y5 = y2+1;
        ll aux1 = abs(x4-x1) + abs(y4-y1);
        ll aux2 = abs(x5-x1) + abs(y5-y1);
        if(x4 == x1 && x2 == x1 && y2 > min(y1, y4) && y2 < max(y1, y4)) aux1 += 2;
        if(y4 == y1 && y2 == y1 && x2 > min(x1, x4) && x2 < max(x1, x4)) aux1 += 2;
        if(y5 == y1 && y2 == y1 && x2 > min(x1, x5) && x2 < max(x1, x5)) aux2 += 2;
        if(x5 == x1 && x2 == x1 && y2 > min(y1, y5) && y2 < max(y1, y5)) aux2 += 2;
        ans += min(aux1, aux2);
    }
    cout << ans << "\n";
}
