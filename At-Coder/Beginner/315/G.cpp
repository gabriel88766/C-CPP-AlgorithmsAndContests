#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binmul(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 0;
    while(b){
        if(b & 1){
            ans += a;
            if(ans > m) ans -= m;
        } 
        a += a;
        if(a > m) a -= m;
        b >>= 1;
    }
    return ans;
}

ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
    if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_euclid(b, a % b, x1, y1); //if b > a then this step reverses it
    x = y1;
    y = x1 - y1 * (a/b); 
    return d;
}

bool find_xy(ll a, ll b, ll c, ll &x, ll &y){ //first solution for x > 0
    ll g = gcd_euclid(abs(a), abs(b), x, y);
    if(c % g) return false;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    if(x < 0){
        x %= (abs(b)/g);
        x += (abs(b)/g);
    }
    x = binmul(x, c/g, abs(b)/g); //if risk of overflow, make x positive (if(x < 0) x %= m, x += m;) and apply mulmod
    if(x <= 0) x += abs(b)/g;
    y = (c - a*x) / b;
    return true;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, a, b, c, x;
    cin >> n >> a >> b >> c >> x;
    ll ans = 0;
    ll g = gcd(b, c);
    for(int i=1;i<=n;i++){
        ll val = x - a * i;
        //solve equation bx + cy = val
        ll x, y;
        if(val <= 0) break;
        if(find_xy(b, c, val, x, y)){
            //bx + cy = val
            // x = x0 + k * (c/g)
            // y = y0 - k * (b/g);
            if(y > n){
                ll d = (y + (b/g) - 1 - n) / (b/g);
                y -= (b/g) * d;
                x += (c/g) * d;
            }
            if(y <= 0) continue;
            ll op1 = (y + (b/g) - 1) / (b/g);
            ll op2 = (x <= n ? (n - x + (c/g))/(c/g) : 0);
            ans += min(op1, op2);
        }
    }
    cout << ans << "\n";
}
