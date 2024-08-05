#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


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
    x = (x * c/g)  % (abs(b)/g); //mulmod  if risk of overflow
    if(x < 0) x += abs(b)/g;
    y = (c - a*x) / (b/g);
    return true;
}

//This code below come from 
//https://github.com/imeplusplus/icpc-notebook/blob/master/math/extended_euclid.cpp
bool crt_auxiliar(ll a, ll b, ll m1, ll m2, ll &ans){
    ll x, y;
    if(!find_xy(m1, m2, b - a, x, y)) return false;
    ll lcm = m1 / __gcd(m1, m2) * m2;
    ans = ((a + x % (lcm / m1) * m1) % lcm + lcm) % lcm;
    return true;
}

// find ans such that ans = a[i] mod b[i] for all 0 <= i < n or return false if not possible
// ans + k * lcm(b[i]) are also solutions
bool crt(int n, ll a[], ll b[], ll &ans){
    if(!b[0]) return false;
    ans = a[0] % b[0];
    ll l = b[0];
    for(int i = 1; i < n; i++){
    if(!b[i]) return false;
        if(!crt_auxiliar(ans, a[i] % b[i], l, b[i], ans)) return false;
        l *= (b[i] / __gcd(b[i], l));
    }
    return true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k, h, w;
        cin >> n >> k  >> w >> h;
        string s;
        cin >> s;
        map<ll, map<ll, ll>> mp; 
        ll cgh = 0, cgw = 0;
        for(int i=1;i<=n;i++){
            auto c = s[i-1];
            if(c == 'L'){
                cgw--;
            }else if(c == 'R'){
                cgw++;
            }else if(c == 'U'){
                cgh++;
            }else{
                cgh--;
            }
            if(cgw >= 2*w) cgw -= 2*w;
            if(cgw < 0) cgw += 2*w;
            if(cgh >= 2*h) cgh -= 2*h;
            if(cgh < 0) cgh += 2*h;
            mp[cgw][cgh]++;
        }
        ll ans = 0;
        
        --k;
        for(auto [x, mp2] : mp){
            for(auto [y, val] : mp2){
                ll difw = (2*w - x) % (2*w);
                ll difh = (2*h - y) % (2*h);
                if(cgw == 0 && cgh != 0){
                    if(x != 0) continue;
                    ll x1, y1;
                    if(find_xy(cgh, 2*h, difh, x1, y1)){
                        if(difh == 0) x1 = 0;
                        ll mul2 = (2*h) / gcd(2*h, cgh);
                        if(x1 <= k) ans += ((k-x1)/mul2 + 1)*val;
                    }
                    continue;
                }else if(cgh == 0 && cgw != 0){
                    if(y != 0) continue;
                    //k*curw == difw
                    ll x1, y1;
                    if(find_xy(cgw, 2*w, difw, x1, y1)){
                        if(difw == 0) x1 = 0;
                        ll mul1 = (2*w) / gcd(2*w, cgw);
                        if(x1 <= k) ans += ((k-x1)/mul1 + 1)*val;
                    }
                    continue;
                }else if(cgw == 0 && cgh == 0){
                    if(x == 0 && y == 0) ans += (k+1)*val;
                    continue;
                }
                //find all :  
                //ki*curw == 2*w - x (mod 2*w) => curw * x + (2*w)*y = difw
                //ki*curh == 2*h - y (mod 2*h)
                ll x1, y1, x2, y2;
                if(find_xy(cgw, 2*w, difw, x1, y1) && find_xy(cgh, 2*h, difh, x2, y2)){
                    // x1 + (2*w)/g k
                    ll mul1 = (2*w) / gcd(2*w, cgw);
                    ll mul2 = (2*h) / gcd(2*h, cgh);
                    ll lc = lcm(mul1, mul2);
                    ll a[2], b[2], ansx;
                    a[0] = x1;
                    b[0] = mul1;
                    a[1] = x2;
                    b[1] = mul2;
                    if(crt(2, a, b, ansx)){
                        if(k >= ansx){
                            ll lo = 0, hi = 1e12;
                            while(lo != hi){
                                ll mid = lo + (hi - lo + 1)/2;
                                bool ok = true;
                                if(mid > (k-ansx)/lc) ok = false;
                                if(ok){
                                    if(mid*lc + ansx <= k);
                                    else ok = false;
                                }
                                if(ok) lo = mid;
                                else hi = mid -1;
                            }
                            ans += val * (lo+1);
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
