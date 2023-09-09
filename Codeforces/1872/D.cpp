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
        ll n, x, y;
        cin >> n >> x >> y;
        ll m = (x*y)/gcd(x,y);
        ll qtt = n/m;
        ll qtp = n/x - qtt;
        ll qtm = n/y - qtt;
        ll Sum = 0; 
        // n + n-1 + ... n-qtt+1 = (qtt*(2*n-qtt+1))/2;
        Sum += (qtp*(2*n-qtp+1))/2;
        // 1 + 2 + ... + qtm
        Sum -= ((qtm)*(1+qtm))/2;
        cout << Sum << "\n";
    }
}
