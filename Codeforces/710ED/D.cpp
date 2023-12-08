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
    ll a1, a2, b1, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    ll x, y;
    bool ispos = find_xy(a1, a2, b2 - b1, x, y);
    ll lc = lcm(a1, a2);
    ll MAX_INT = 2e9+1;
    if(ispos){
        ll fs = a1 * x + b1;
        for(int i = 30; i>=0; i--){
            ll aux = 1 << i;
            if(MAX_INT/aux > lc){
                ll jmp = lc * aux;
                while((fs+jmp - b2)/a2 < 0){
                    fs += jmp;
                }
            }
        }
        if((fs - b2)/a2 < 0) fs += lc; 
        ll ls = fs;
        //cout << fs << " " << ls << " " << lc << "\n";
        for(int i = 30; i>=0; i--){
            ll aux = 1 << i;
            if(MAX_INT/aux > lc){
                ll jmp = lc * aux;
                while(L > fs + jmp) fs += jmp;
                while(R >= ls + jmp) ls += jmp;
            }
        }
        if(fs < L) fs += lc;
        if(ls <= R && fs >= L) cout << (ls-fs)/lc + 1 << "\n";
        else cout << "0\n";
    }else cout << "0\n";
}
 