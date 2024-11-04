#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll ask(ll a, ll b){
    cout << "xor " << a << " " << b << "\n";
    cout.flush();
    ll ans;
    cin >> ans;
    return ans;
}
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
        //from 1 to n, there are 3 missing
        ll l = 1, r = n;
        ll val = ask(l, r);
        if(val != 0){
            ll bt = 1;
            while(bt*2 < n) bt *= 2;
            for(ll x = bt; x >= 1; x >>= 1){
                if(l+x <= r && ask(l+x, r) == val) l += x;
                if(r-x >= l && ask(l, r-x) == val) r -= x;
            }
            ll a1 = l, a2 = r, a3 = ask(l+1, r-1);
            cout << "ans " << a1 << " " << a2 << " " << a3 << "\n";
            cout.flush();
        }else{
            ll mn = -1;
            for(ll i=2;;i*=2){
                assert(i <= 2e18);
                ll cur = ask(1, i-1);
                if(cur != 0){
                    mn = cur;
                    break;
                }
            }
            ll l = mn + 1, r = n;
            ll bt = 1;
            while(bt*2 < n) bt *= 2;
            for(ll x = bt; x >= 1; x >>= 1){
                if(r-x >= l && ask(l, r-x) == mn) r -= x;
            }
            l = r ^ mn;
            cout << "ans " << mn << " " << l << " " << r << "\n";
            cout.flush();
        }
    }
}
