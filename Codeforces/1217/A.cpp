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
        ll s, i, f;
        cin >> s >> i >> f;
        if(s + f > i){
            //find x, s+x > i + f - x => 2x > i + f - s, x > (i+f-s)/2
            ll aux = i + f - s;
            ll x = max(0LL, (aux+2)/2);
            cout << f - x + 1 << "\n";
        }else cout << "0\n";
    } 
}
