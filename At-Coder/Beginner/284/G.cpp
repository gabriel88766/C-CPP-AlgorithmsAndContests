#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binpow(ll a, ll b, ll m){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    cin >> n >> m;
    ll fat = 1, ans = 0, sum = 0;
    for(ll km=1;km<=n;km++){
        //k from 0 to km - 1
        fat *= (n - km + 1);
        fat %= m;
        ll curp = n-km == 0 ? 1 : binpow(n, n-km, m);
        // cout << km << " " << fat << " " << curp << " ";
        curp = (curp * fat) % m;
        ll curk = ((km * (km-1))/2) % m;

        // cout << "but " << curp << " " << curk << "\n";
        ans = (ans + curp * curk) % m;
    }
    cout << ans << "\n";
}
