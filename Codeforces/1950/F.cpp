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
        int a, b, c;
        cin >> a >> b >> c;
        if(a != (c-1)) cout << "-1\n";
        else if(a == 0){
            cout << b << "\n";
        }else{
            int ans = 0;
            int x = (32 - __builtin_clz(a));
            b -= (1 << x) - c;
            ans += x;
            if(b >= 1) ans += (b-1)/c + 1;
            cout << ans << "\n";
        }
    }
}
