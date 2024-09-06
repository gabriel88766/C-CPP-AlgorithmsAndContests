#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sum(ll n, ll k, ll i){
    //k, k+1, ... k+n-1;
    ll s1 = ((k + k + i - 1) * i)/2;
    ll s2 = ((k + k + n - 1) * n)/2;
    s2 -= s1;
    return s1 - s2;
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
        ll lo = 1, hi = n;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            if(sum(n, k, mid) < 0) lo = mid;
            else hi = mid - 1;
        }
        assert(lo != n);
        cout << min(abs(sum(n, k, lo)), abs(sum(n, k, lo+1))) << "\n";
    }
}
