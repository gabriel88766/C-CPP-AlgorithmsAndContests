#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(ll n){
    while(n != 1){
        if(n % 2) return false;
        else n /= 2;
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
        ll n, m;
        cin >> n >> m;
        ll g = gcd(n, m);
        n /= g, m /= g;
        if(check(m)){
            n = (n % m);
            ll ans = 0;
            ll p = 0;
            for(ll i=m/2;i>=1; i/=2){
                ++p;
                if(n >= i){
                    n -= i;
                    ans += ((1 << p)-1)*g*i; 
                }
            }
            cout << ans << "\n";
        }else{
            cout << "-1\n";
        }
    }
}
