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
        ll h, d;
        cin >> h >> d;
        if(h == 1){ //then need to rest at x = 0
            cout << 2*d << "\n";
            continue;
        }
        //then I think he doesn't need to rest at x = 0, go ahead.
        ll lo = 0, hi = d - 1;
        auto sum = [](ll x){
            ll ans = x;
            ans *= (x+1);
            return ans / 2;
        };
        auto calch = [&](ll h, ll d, ll mid){
            ll mnc = d / (mid + 1);
            //mnc * x + (mnc + 1) * (mid + 1 - x) = d
            assert(mnc * (mid + 1) <= d);
            assert((mnc + 1) * (mid + 1) >= d);
            ll y = d % (mid + 1);
            ll x = mid + 1 - y;
            // cout << x << " " << y << " " << mnc << endl;
            assert(mnc * x + (mnc + 1) * y == d);
            ll tth = mid + h;
            tth -= sum(mnc) * x;
            tth -= sum(mnc + 1) * y;
            return tth;
        };
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            auto tth = calch(h, d, mid);
            if(tth > 0) hi = mid;
            else lo = mid + 1;
        }
        cout << d + lo << "\n";
    }
    
}
