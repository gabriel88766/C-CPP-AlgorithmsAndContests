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
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    if(x < a){
        swap(x, a);
        d = -d;
    }

    if(x == a) cout << "0\n";
    else{ //a < x
        if(d <= 0){
            cout << x - a << "\n";
        }else{
            if(a + d*(n-1) <= x) cout << x - a - d*(n-1) << "\n";
            else{
                ll r = abs(x) % d;
                ll dif = abs(r - (abs(a) % d));
                dif = min(dif, d - dif);
                cout << dif << "\n";
            }
        }
    }
}
