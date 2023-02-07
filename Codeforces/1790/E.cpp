#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ull t;
    cin >> t;
    while(t--){
        ull n, a, b = 0;
        cin >> n;
        a = n;
        ull pot, pot2;
        for(int i=0; (1 << i) <= n; i++){
            pot = 1 << i;
            pot2 = pot * 2;
            if(a & pot2){
                a |= pot;
                b |= pot;
            }
        }
        if((a%2) != (b%2)) cout << "-1\n";
        else{
            if( a^b == n && (a+b)/2 == n) cout << a << " " << b << "\n";
            else cout << "-1\n";
        }
    }

}
