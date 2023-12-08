#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sdig(ll n){
    ll ans = 0;
    while(n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, s;
    cin >> n >> s;
    //number from 1 to n , x - sdig(x) >= s
    if(n > s){
        ll ans = n - s;
        for(ll i = s+1; i <= min(s + 200, n);i++){ //sdig <= 9*18
            if(i - sdig(i) < s) ans--;
        }
        cout << ans << "\n";
    }else cout << "0\n";
}
