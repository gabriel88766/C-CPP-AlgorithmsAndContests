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
    // ll g = 13;
    // for(int i=5;i<=10000;i++){
    //     g = gcd(i, g) + g;
    //     if(g == 3*i) cout << i << "\n";
    // }
    // cout << g << "\n";
    ll x = 4, val = 13;
    const ll N = 1e15;
    while(x <= N){
        ll nx, nval;
        ll k = -1;
        for(ll i = 2; i*i<=val;i++){
            //try find first (x+k) % i == 0 and (val + k - 1) % i == 0 simultaneously (k >= 1)
            int r1 = x % i;
            int r2 = (val - 1 + i) % i;
            if(r1 == r2){
                int nk = i - r1;
                if(k == -1 || nk < k) k = nk; 
            }
        }
        if(k == -1){
            //then make val + k - 1 % (x+k) == 0
            //(val - x - 1)
            //val == 2x + n, k = n-1
            k = val - 2*x - 1;
        }
        nx = x + k;
        nval = val + k - 1 + gcd(val + k - 1, x + k);
        
        if(nx > N){
            cout << N-x + val << "\n";
            break;
        }
        x = nx;
        val = nval;
    }
}
