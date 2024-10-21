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
    ll n;
    cin >> n;
    ll cx = 1;
    ll ans = 0;
    for(int i=0;;i++){
        ll nx = min(cx*10 - 1, n);
        ll cur = nx - cx + 1;
        ll curp;
        if(cur % 2){
            curp = cur % MOD;
            curp *= ((cur+1)/2)%MOD;
        }else{
            curp = (cur/2) % MOD;
            curp *= (cur+1) % MOD;
        }
        ans += curp;
        ans %= MOD;
        if(nx == n) break;
        cx *= 10;
    }
    cout << ans << "\n";
}
