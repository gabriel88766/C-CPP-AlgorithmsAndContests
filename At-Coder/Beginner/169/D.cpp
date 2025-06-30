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
    ll ans = 0, n;
    cin >> n;
    for(ll i=2;i*i<=n;i++){
        ll cnt = 0;
        while(n % i == 0){
            cnt++;
            n /= i;
        }
        if(cnt != 0){
            if(cnt < 3) ans += 1;
            else if(cnt < 6) ans += 2;
            else if(cnt < 10) ans += 3;
            else if(cnt < 15) ans += 4;
            else if(cnt < 21) ans += 5;
            else if(cnt < 28) ans += 6;
            else if(cnt < 36) ans += 7;
            else if(cnt < 45) ans += 8;
            else assert(false);
            //cnt is at most floor of log2(10^12) = 39
        }
    }
    if(n != 1) ans++;
    cout << ans << "\n";
}
