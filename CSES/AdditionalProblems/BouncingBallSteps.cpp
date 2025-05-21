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
        ll n, m, k;
        cin >> n >> m >> k;
        ll pi = (lcm(2*(n-1), 2*(m-1)));
        // cout << pi << "\n";
        ll bad = k/pi;
        bad += (k + pi/2)/pi;
        ll total = k/(n-1) + k/(m-1);
        total -= bad;
        ll x = k % (2*(n-1));
        x = min(x, 2*n-2-x);
        ll y = k % (2*(m-1));
        y = min(y, 2*m-2-y);
        cout << x+1 << " " << y+1 << " " << total << "\n"; 
    }
}
