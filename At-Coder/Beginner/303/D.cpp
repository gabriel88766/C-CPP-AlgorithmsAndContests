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
    ll x, y, z;
    string s;
    cin >> x >> y >> z >> s;
    ll a0 = 0, a1 = z;
    for(auto &c : s){
        ll na0, na1;
        if(c == 'a'){
            na0 = min(a0 + x, a1 + min(z + x, z + y));
            na1 = min(a1 + y, a0 + min(x + z, z + y));
        }else{
            na0 = min(a0 + y, a1 + min(z + x, z + y));
            na1 = min(a1 + x, a0 + min(z + x, z + y));
        }
        a0 = na0;
        a1 = na1;
    }
    cout << min(a0, a1) << "\n";
}
