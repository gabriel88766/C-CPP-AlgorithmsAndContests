#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ull mx = 0xffffffffffffffff;
pair<bool, ull> binpow(ull a, ull b){
    if(a == 0) return {false, 0};
    ull ans = 1;
    bool inf = false;
    while(b > 0){
        if(b & 1){
             if(mx/ans >= a) ans *= a;
             else inf = true;
        }
        b >>= 1;
        if(b){
            if(mx/a >= a) a *= a;
            else inf = true;
        }
    }
    return {inf, ans};
}

ull kthroot(ull n, ull k){
    ull lo = 0, hi = mx;
    while(lo != hi){
        ull mid = (hi - lo == mx ? 1ULL << 63 :  lo + (hi - lo + 1)/2);
        auto [ok, ans] = binpow(mid, k);
        if(!ok && ans <= n) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ull a, k;
        cin >> a >> k;
        cout << kthroot(a, k) << "\n";
    }
}
