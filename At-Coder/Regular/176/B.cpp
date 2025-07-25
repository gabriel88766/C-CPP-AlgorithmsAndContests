#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
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
        ll n, m, k;
        cin >> n >> m >> k;
        if(n >= m){
            n -= ((n-m)/(m-k) + 1) * (m-k);
            assert(n >= k);
            assert(n < m);
        }
        if(k == (m - 1)){
            if(n >= k) cout << "0\n";
            else cout << binpow(2, n, 10) << "\n";
        }else{
            cout << binpow(2, n, 10) << "\n";
        }
    }
}
