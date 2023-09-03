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
    int q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        ll ttn = n / m;
        ll x = m % 10;
        ll S1 = 0, num;
        for(int i=1;i<=11;i++){
            if(i != 1 && x == (i*x) % 10){
                num = i-1;
                break;
            }
            S1 += (i*x) % 10;
        }
        ans += (ttn / num) * S1;
        for(int i = 1; i <= ttn % num; i++){
            ans += (i*x) % 10;
        }
        cout << ans << "\n";
    }
}
