#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll a, m;
        cin >> a >> m;
        ll g = gcd(a, m);
        ll x = m / g;
        ll phi = x;
        for(ll i=2;i*i<=x;i++){
            if(!(x % i)){
                phi -= phi/i;
                while(!(x % i)){
                    x /= i;
                }
            }
        }
        if(x != 1){
            phi -= phi / x;
        }
        cout << phi << "\n";
    }
}
