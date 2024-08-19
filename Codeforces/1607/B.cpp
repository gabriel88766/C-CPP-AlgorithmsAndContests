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
        ll x, n;
        cin >> x >> n;
        //odd +1 -2 -3 +4 +5 -6 -7 +8 +9
        //even -1 +2 +3 -4 -5 +6 +7
        ll aux = (n/4) * 4 + 1;
        for(ll k = aux; k<=n;k++){
            if(x % 2) x += k;
            else x -= k;
        }
        cout << x << "\n";
    }
}
