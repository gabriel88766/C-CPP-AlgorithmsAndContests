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
    ll a, b, x;
    cin >> a >> b >> x;
    if(a + b <= x){
        ll lo = 1, hi = 1'000'000'000;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            ll cst = a * mid;
            ll cdg = to_string(mid).size();
            cst += cdg * b;
            if(cst > x) hi = mid - 1;
            else lo = mid;
        }
        cout << lo << "\n";
    }else cout << "0\n";
}
