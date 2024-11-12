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
    ll a, b, c, x;
    cin >> a >> b >> c >> x;
    if(x <= a) cout << "1.00000000000000\n";
    else if(x > b) cout << "0.00000000000\n";
    else{
        double odd = c;
        odd /= (b-a);
        cout << setprecision(15) << fixed << odd << "\n";
    }
}
