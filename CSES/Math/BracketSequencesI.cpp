#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

ll ans[1000005];

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) 
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
ll divmod(ll a, ll b, ll m = MOD){
    return (a * binpow(b, m-2, m)) % m;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll curval = 1;
    for(int i=2;i<=1000000;i+=2){
        ll half = i/2;
        curval = (curval * i) % MOD;
        curval = (curval * (i-1)) % MOD;
        curval = divmod(curval, half);
        curval = divmod(curval, half+1);
        ans[i] = curval;
    }
    int n;
    cin >> n;
    cout << ans[n];
}
