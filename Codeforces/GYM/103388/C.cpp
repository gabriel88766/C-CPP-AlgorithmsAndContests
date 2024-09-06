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

bool find_xy(ll a, ll b, ll c, ll &x, ll &y, ll &g){ //first solution for x > 0
    g = gcd_euclid(abs(a), abs(b), x, y);
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
    int b, l;
    cin >> b >> l;
    vector<int> po(l);
    po[0] = 1;
    for(int i=1;i<l;i++){
        po[i] = po[i-1] * b;
        po[i] %= (b+1);
    }
    vector<int> num(l);
    int cg = 0;
    for(int i=l-1;i>=0;i--){
        cin >> num[i];
        cg += (num[i] * po[i]);
        cg %= (b+1);
    }
    if(cg == 0){
        cout << "0 0\n";
    }else{
        for(int i=l-1;i>=0;i--){
            // try  po[i] * x == cg mod(b+1)
            // po[i] * x + (b+1) * y = cg;
            ll x, y, g;
            if(!find_xy(po[i], b+1, cg, x, y, g)) continue;
            while(x + (b+1)/g <= num[i]) x += (b+1)/g;
            if(x <= num[i]){
                cout << l-i << " " << num[i]-x << "\n";
                return 0;
            }

        } 
        cout << "-1 -1\n";
    }
}
