#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Frac{
    ll a,  b;
    Frac(ll a, ll b){
        ll g = gcd(abs(a), abs(b));
        if(b < 0){
            a = -a;
            b = -b;
        }
        this->a = a / g;
        this->b = b / g;
    }
    Frac() : a(0), b(1) {}
    bool operator< (const Frac &f) const{
        return a * f.b < b * f.a;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    map<Frac, ll> mp;
    // ll ini = 0;
    for(int i=0;i<n;i++){
        ll k, b;
        cin >> k >> b;
        if(k == 0) continue;
        Frac f(-b, k);
        if(k > 0){
            mp[f] += k;
        }else{
            mp[f] -= k;
            // ini += k;
        }
        //kx + b = 0 => x = -b/k
    }
    int ans = 0;
    for(auto [a, b] : mp){
        // cout << a.a << ", " << a.b << "\n";
        if(b != 0) ans++;
    }
    cout << ans << "\n";
}
