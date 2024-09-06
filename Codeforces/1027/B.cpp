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
    ll n, q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        ll x, y;
        cin >> x >> y;
        ll ans = 0;
        ll to = x/2;
        ll te = (x-1)/2;
        if((x+y) % 2){
            ans += (n*n + 1)/2;
            swap(to, te);
        }
        

        ans += to * ((n+1)/2);
        ans += te * (n/2);
        ans += (y+1)/2;
        cout << ans << "\n";
    }
}
