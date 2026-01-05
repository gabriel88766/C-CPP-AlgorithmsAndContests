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
        ll l, r, x;
        cin >> l >> r >> x;
        x *= 2;
        //l+l = 1
        //l+l+1 = 1
        //l+l+2 = 2
        //l+l+3 = 2
        //...
        //r+r-2 = 2
        //r+r-1 = 1
        //r+r = 1
        if(x >= 2*l && x <= 2*r){
            ll d1 = (x - 2*l)/2;
            ll d2 = (2*r - x)/2;
            cout << 1 + min(d1,d2) << "\n";
        }else cout << "0\n";
    }
}
