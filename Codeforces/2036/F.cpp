#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll xorf(ll l, ll r){
    if(l >= r - 10){
        ll ans = 0;
        for(ll i=l;i<=r;i++) ans ^= i;
        return ans;
    }else{
        ll ans = 0;
        while(l % 4){
            ans ^= l;
            l++;
        }
        while(r % 4 != 3){
            ans ^= r;
            r--;
        }
        return ans;
    }
}
ll solve(int l, int r, int i, int k){
    int mod = 1 << i;
    int ans = 0;
    for(int j=l;j<=r;j++){
        if((j % mod) == k) continue;
        ans ^= j;
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin);
    // freopen("out1", "w", stdout); //test input
    int t;
    cin >> t;
    while(t--){
        ll l, r, i, k;
        cin >> l >> r >> i >> k;
        // cout << solve(l, r, i, k) << "\n";
        // continue;
        ll ans = xorf(l, r);
        ll jmp = 1 << i;
        ll fn = 1LL << 61;
        fn += k;
        for(ll j = 1LL << 60; j >= jmp; j >>= 1){
            while(fn-j >= l) {fn -= j;}
        }
        ll ln = k;
        for(ll j = 1LL << 60; j>= jmp; j>>=1){
            while(ln + j <= r){ ln += j; }
        }
        if(ln >= fn && fn >= l && ln <= r){
            ll ttn = ((ln - fn) >> i) + 1;
            if(ttn % 2) ans ^= k;
            ans ^= xorf(fn >> i, ln >> i) << i;
        }
        cout << ans << "\n";
    }
}
 