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
    bool ok = false;
    ll x, y, r[3], sz, cx;
    cin >> x >> y >> r[0] >> r[1] >> r[2];
    //case 1:
    sz = (r[0]+y-1)/y + (r[1]+y-1)/y + (r[2]+y-1)/y;
    if(sz <= x) ok = true;
    //case 2:
    for(int j=0;j<3;j++){
        cx = x - (r[j] + y - 1) / y;
        if(cx <= 0) continue;
        sz = 0;
        for(int k=0;k<3;k++){
            if(k != j) sz += (r[k] + cx - 1) / cx;
        }
        if(sz <= y) ok = true;
    }
    //case 3 and 4
    swap(x, y);
    //case 1:
    sz = (r[0]+y-1)/y + (r[1]+y-1)/y + (r[2]+y-1)/y;
    if(sz <= x) ok = true;
    //case 2:
    for(int j=0;j<3;j++){
        cx = x - (r[j] + y - 1) / y;
        if(cx <= 0) continue;
        sz = 0;
        for(int k=0;k<3;k++){
            if(k != j) sz += (r[k] + cx - 1) / cx;
        }
        if(sz <= y) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
