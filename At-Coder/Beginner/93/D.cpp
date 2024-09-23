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
    int q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        ll lo = 0, hi = 2e9;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            //check if the first mid products (Bi * Aj) are lower than a*b
            bool ok = true;
            ll mv = 0;
            for(ll i = max(mid/2 - 5, 1LL); i <= min(mid/2 + 5, mid); i++){
                ll x = i;
                if(x >= a) x++;
                ll y = mid - i + 1;
                if(y >= b) y++;
                if(x*y >= a*b) ok = false;
            }

            if(ok) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}
