#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll qnt(ll sz, ll k){ //log n
    if(sz < k) return 0;
    if(sz % 2) return 2*qnt(sz/2, k) + 1;
    else return 2*qnt(sz/2, k);
}

ll solve(ll sz, ll k){
    ll l = 1, r = sz;
    if(sz < k) return 0;
    ll m = (l + r)/2;
    if((r-l+1) % 2) return m + 2*solve(m-1, k) + m*qnt(m-1, k);
    else return 2*solve(m, k) + m * qnt(m, k); 
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
}
