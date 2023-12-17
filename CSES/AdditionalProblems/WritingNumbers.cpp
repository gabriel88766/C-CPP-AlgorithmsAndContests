#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ll calc(ll n){
    //how many times d appers between 1 and n ?
    ll ans = 0;
    ll cur = 1;
    for(cur = 1; ; cur *= 10){
        if(cur > n) break;
        ll x = n / cur;
        x /= 10;
        ans += x * cur; 
        ll xx = x * 10 * cur + cur;
        if(n >= xx) ans += min(n - xx + 1, cur);
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    ll lo = 1, hi = 1e18;
    hi--;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if(calc(mid) <= n) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}
