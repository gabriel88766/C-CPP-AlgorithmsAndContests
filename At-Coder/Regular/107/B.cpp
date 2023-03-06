#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, k, ans = 0;
    cin >> n >> k;
    for(int i=2;i<=(2*n);i++){
        ll sa = i, sb = i-k;
        if(sb <= 1) continue;
        if(sb >= (2*n+1)) continue;
        ll posa = min(2*n+1-sa, sa-1);
        ll posb = min(2*n+1-sb, sb-1);
        ans += posa*posb;
    }
    cout << ans;


}
