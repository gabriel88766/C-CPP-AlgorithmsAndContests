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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    vector<int> pl(2*max(n, m) + 1, -1);
    ll lc = lcm(n, m);
    for(int i=0;i<n;i++){
        cin >> a[i];
        pl[a[i]] = i;
    }
    //at most min(n, m) equals (congruency mod lcm)
    vector<ll> eq;
    for(int i=0;i<m;i++){
        cin >> b[i];
        if(pl[b[i]] != -1){
            int c1 = pl[b[i]]; //mod n
            int c2 = i; //mod m
            ll x, y;
            if(find_xy(n, -m, c2-c1, x, y)){
                //nx + c1
                assert(n*x+c1 < lc);
                eq.push_back(n*x+c1);
            }
        }
    }
    sort(eq.begin(), eq.end());
    ll lo = 1, hi = 2e18;
    ll sz = eq.size();
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        ll cur = (mid / lc) * (lc - sz);
        ll cg = mid % lc;
        cur += cg;
        for(int j=0;j<eq.size();j++){
            if(eq[j] + 1 <= cg) cur--;
            else break;
        }
        if(cur < k) lo = mid + 1;
        else hi = mid;
    }
    cout << lo << "\n";
    
    
}
