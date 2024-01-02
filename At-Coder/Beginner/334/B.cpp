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
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    ll bg = 2e18;
    ll k = bg/m+1;
    assert(a - k*m < l && a + k*m > r);
    ll lo = -k, hi = k;
    for(ll jmp = k/2;jmp>=1;jmp>>=1){
        while((lo + jmp)*m + a < l) lo += jmp;
        while((hi - jmp)*m + a > r) hi -= jmp;
    }
    lo++;
    hi--;
    cout << hi-lo+1 << "\n";
}
