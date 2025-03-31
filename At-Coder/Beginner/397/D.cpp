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
    ll n;
    cin >> n;
    bool ok = false;
    for(ll d = 1; d*d*d <= n; d++){
        //d = x - y
        if(n % d) continue;
        ll val = n / d;
        //x^2 + xy + y^2 = val
        //x - y = d
        //thus:
        //y^2 + 2yd + d^2 + yd + y^2 + y^2 = 3y^2 + 3yd + d^2 = val
        ll a = 1;
        ll b = d;
        ll c = d*d - val;
        if(c % 3) continue;
        else c /= 3;
        if(b*b - 4 * a * c >= 0){
            ll dt = b*b - 4 * a * c;
            ll x = sqrt(dt);
            while(x*x > dt) x--;
            while((x+1)*(x+1) <= dt) x++;
            if(x*x == dt){
                ll val = -b + x;
                if(val > 0 && val % 2 == 0){
                    cout << val/2 + d << " " << val/2 << "\n";
                    ok = true;
                    break;
                }
            }
        }
    }
    if(!ok) cout << "-1\n";
}
