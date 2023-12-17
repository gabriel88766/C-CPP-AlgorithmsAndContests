#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Frac{
    ll a, b;
    Frac(string s){
        int qt = s.size();
        a=0, b = 1;
        for(int i=0;i<qt;i++) b *= 10;
        for(auto x : s){
            a *= 10;
            a += x - '0';
        }
        ll g = gcd(a, b);
        a /= g;
        b /= g;
    }
};

__uint128_t mul64(uint64_t a, uint64_t b) {
    return (__uint128_t)a * b;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    string s;
    char c;
    cin >> n >> c >> s >> n;
    Frac f(s);
    cout << f.a << " /" << f.b << "\n";
    ll num = 1, den = 1;
    while(num <= n && den <= n){
        ll nn = f.b * num + f.a * den;
        ll nd = f.b * den * 2;
        ll g = gcd(nn, nd);
        nn /= g;
        nd /= g;
        cout << nn << " " << nd << "\n";
        if(nn <= n && nd <= n){
            num = nn;
            den == nd;
        }else break;
    }
    cout << num << " " << den << "\n";

}
