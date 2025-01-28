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
        ll l, r, ans = 0;
        cin >> l >> r;
        if(r >= 3*l - 3){
            cout << r/2 << "\n";
        }else{
            //l <= r < 3*l
            //try sqrt algo
            ll hf = r / 2;
            if(hf >= l) ans += hf - l + 1;
            ll lb = 1;
            ll hb = l-1;
            while(lb <= hb){
                ll mt = r / lb;
                if(mt == 1) break;
                ll ln = r / mt;
                ln = min(ln, hb);
                //find the first number that (mt - 1) * x >= l
                ll x = (l + mt-2) / (mt - 1);
                if(x <= ln) ans += ln - max(x, lb) + 1;
                lb = ln + 1;
            }
            cout << ans << "\n";

        }
    }
}
