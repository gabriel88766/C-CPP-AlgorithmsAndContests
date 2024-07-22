#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;

ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
    if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
        x = 1; y = 0;
        return a;
    }
    ll d = gcd_euclid(b, a % b, y, x); //if b > a then this step reverses it
    y -= x * (a/b); 
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

//This code below comes from 
//https://github.com/imeplusplus/icpc-notebook/blob/master/math/extended_euclid.cpp
bool crt_auxiliar(ll a, ll b, ll m1, ll m2, ll &ans){
    ll x, y;
    if(!find_xy(m1, m2, b - a, x, y)) return false;
    ll lc = lcm(m1, m2);
    ans = ((a + x % (lc / m1) * m1) % lc + lc) % lc;
    return true;
}

// find ans such that ans = a[i] mod b[i] for all 0 <= i < n or return false if not possible
// ans + k * lcm(b[i]) are also solutions
bool crt(vector<ll> &a, vector<ll> &b, ll &ans){
    int n = a.size();
    if(!b[0]) return false;
    ans = a[0] % b[0];
    ll l = b[0];
    for(int i = 1; i < n; i++){
        if(!b[i]) return false;
        if(!crt_auxiliar(ans, a[i] % b[i], l, b[i], ans)) return false;
        l = lcm(b[i], l);
    }
    return true;
}

ll binexp(ll a, ll b, ll m){
    ll ans = 1;
    a %= m;
    while(b){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll divmod(ll a, ll b, ll m){
    a %= m;
    ll x, y;
    if(find_xy(b, m, 1, x, y)){
        return (a * x)%m;
    }else{
        assert(false); //bug found
        return -1;
    }
}
//begin problem
vector<pair<ll,ll>> f;
vector<vector<ll>> fat;

void precmpt(int i){
    ll p = f[i].first;
    ll x = f[i].second;
    fat[i].resize(x+1);
    fat[i][0] = fat[i][1] = 1;
    for(int j=2; j<x;j++){
        ll aux = j;
        while(!(aux % p)) aux /= p;
        fat[i][j] = (fat[i][j-1] * aux) % x;
    }
}

ll powfat(ll n, ll p){
    ll x = 1;
    ll ans = 0;
    while(n/x >= p){
        x *= p;
        ans += n/x;
    }
    return ans;
}

ll fatmod(ll n, int i){
    assert(n >= 0);
    ll x = f[i].second;
    assert(x > 1);
    ll ans = binexp(fat[i][x-1], n/x, x);
    if(n/x >= 1) ans = (ans * fatmod(n/x, i)) % x;
    ans = (ans * fat[i][n%x]) % x;
    return ans;
}

ll binmodx(ll n, ll k, int i){
    ll x = f[i].second;
    ll p = f[i].first;
    ll ans = divmod(fatmod(n, i), (fatmod(k, i)*fatmod(n-k, i))%x, x);
    ans = (ans * binexp(p, powfat(n, p) - powfat(k, p) - powfat(n-k, p), x)) % x;
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t, m;
    cin >> t >> m;
    ll aux = m;
    for(int i=2;i*i<=m;i++){
        ll p = 1;
        while(!(aux % (p*i))) p *= i;
        if(p != 1) f.push_back({i, p});
        aux /= p;
    }
    if(aux != 1) f.push_back({aux, aux});
    fat.resize(f.size());
    for(int i=0;i<f.size();i++) precmpt(i);
    vector<ll> ms;
    for(int i=0;i<f.size();i++) ms.push_back(f[i].second);
    while(t--){
        ll n, k;
        cin >> n >> k;
        if(m == 1) cout << "0\n";
        else{
            vector<ll> cg(f.size());
            for(int i=0;i<f.size();i++){
                cg[i] = binmodx(n, k, i);
            }
            ll ans;
            if(crt(cg, ms, ans)) cout << ans << "\n";
            else exit(-1);
        }
    }

}
//not the answer 162590298313536289