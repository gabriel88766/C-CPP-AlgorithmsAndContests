#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sz[51];
ll pn[51];

ll solve(int n, ll x){
    if(x == 0) return 0;
    if(sz[n] == x) return pn[n];
    assert(sz[n] >= x);
    if(sz[n-1] + 1 >= x) return solve(n-1, x-1);
    if(sz[n-1] + 2 == x) return 1 + pn[n-1];
    assert(2*sz[n-1] + 2 >= x);
    return pn[n-1] + 1 + solve(n-1, x - sz[n-1] - 2);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sz[0] = 1;
    pn[0] = 1;
    for(int i=1;i<=50;i++){
        sz[i] = 3 + 2*sz[i-1];
        pn[i] = 1 + 2*pn[i-1];
        // cout << i << " " << sz[i] << " " << pn[i] << "\n";
    }
    ll n, x;
    cin >> n >> x;
    cout << solve(n, x) << "\n";
}
