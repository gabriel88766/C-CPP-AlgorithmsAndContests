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
        ll a, b, c;
        cin >> a >> b >> c;
        ll lo = 0, hi = 1e9;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            bool ok = true;
            if(mid > min(a, c)) ok = false;
            ll xtra = a + b + c - 2*mid;
            if(xtra < mid) ok = false;
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}
