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
        ll n;
        cin >> n;
        ll x = sqrt(n);
        while(x*x > n) x--;
        while((x+1)*(x+1) <= n) x++;
        if(n == 1) cout << "0\n";
        else if(n == 2) cout << "1\n";
        else if(n == 3) cout << "2\n";
        else{
            ll tt = 8 + 3 * (4 * x - 8) + 4 * (x * x - 4 * x + 4);
            tt /= 2;
            ll r = n - x*x;
            if(r > x){
                tt += 2 * x - 1;
                r -= x;
            }
            if(r > 0) tt += 2 * r - 1;
            cout << tt << "\n";
        }
    }
}
