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
        ll n, x;
        cin >> n >> x;
        ll ans = 0, cs = 0;
        ll mx = -INF_LL;
        for(int i=0;i<n;i++){
            ll a, b, c;
            cin >> a >> b >> c;
            cs += (b-1) * a;
            mx = max(mx, b*a - c);
        }
        if(cs >= x) cout << "0\n";
        else if(mx > 0){
            cout << (x - cs + mx - 1) / mx << "\n";
        }else cout << "-1\n";
    }
}
