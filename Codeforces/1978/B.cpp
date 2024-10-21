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
        ll n, a, b;
        cin >> n >> a >> b;
        ll bk = b > a ? b-a : 0;
        if(bk > n) bk = n;
        ll fb = b;
        ll lb = b - bk + 1;
        ll ans = 0;
        if(bk){
            ans += ((fb + lb) * bk)/2;
        }
        ans += (n-bk)*a;
        cout << ans << "\n";
    }
}
