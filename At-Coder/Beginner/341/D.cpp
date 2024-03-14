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
    ll n, m, k;
    cin >> n >> m >> k;
    if(n > m) swap(n, m);
    ll lc = lcm(n, m);
    ll qt = lc/n + lc/m - 2;
    ll qtk = (k-1)/qt;
    ll aux = qtk*lc;
    k -= qtk*qt;
    ll lo = aux, hi = aux + lc;
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        ll nqt = (mid - aux)/n + (mid - aux)/m;
        if(nqt >= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}
