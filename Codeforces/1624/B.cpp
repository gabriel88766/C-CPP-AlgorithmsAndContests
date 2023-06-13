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
        int a,b,c;
        cin >> a >> b >> c;
        bool ok = false;
        int d = b-a + b;
        if(!(d % c) && d/c > 0) ok = true;
        d = b - (c-b);
        if(!(d % a) && d/a > 0) ok = true;
        d = a+c;
        if(!(d % 2)){
            d = d /= 2;
            if(!(d % b) && d/b > 0){ ok = true;}
            
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
