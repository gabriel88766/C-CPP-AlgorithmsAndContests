#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//find a^x == b mod (m) if exists;
//x = np-q, a^x == b mod(m) thus a^np == a^q * b (mod m)
// -1 if not found
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

ll dlog(ll a, ll b, ll m){
    a %= m; b %= m;
    //if(a == 0 && b == 1) return 0; //if 0^0 == 1
    //if(a == 0 && b == 0 && m == 1) return 0; //if 0^0 == 1
    if(a == 0 && b == 0) return 1;
    if(a == 0) return -1;   
    ll g, add = 0, k = 1;
    while((g = gcd(a, m)) > 1){
        if(b == k) return add;
        if(b % g) return -1;
        b /= g;
        m /= g;
        k = (k * (a / g)) % m;
        add++;
    }
    if(b == k) return add;
    //ka^(x-1) == b (mod m) => k*a^(np) == a^q * b (mod m); return np-q+1, p>=1 && q < n
    ll n = ceil(sqrt(m)) + 0.01; //n*n > m
    ll aux = binpow(a, n, m);
    map<ll, ll> mp; //change to unordered if you want "O(1)"
    ll bx = b;
    mp[bx] = 0;
    for(int i=1;i<n;i++){
        bx = (bx * a) % m;
        mp[bx] = i;
    }
    ll ax = k;
    for(ll i=1;i<=n;i++){
        ax = (ax * aux) % m;
        if(mp.count(ax)){
            return n*i - mp[ax] + add;
        }
    }
    return -1;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll a, b, m;
        cin >> a >> b >> m;
        ll ans = dlog(a, b, m);
        cout << ans << "\n";
    }
}
