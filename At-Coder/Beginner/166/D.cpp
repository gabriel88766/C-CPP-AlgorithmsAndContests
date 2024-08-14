#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll p5[1500];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int nmax;
    for(ll i = 0; ;i++){
        p5[i] = i*i*i*i*i;
        if(p5[i] - p5[i-1] > 1'000'000'000){
            nmax = i-1;
            break;
        }
    }
    ll x;
    cin >> x;
    for(int i=-nmax;i<=nmax;i++){
        for(int j=-nmax;j<=nmax;j++){
            ll val1 = (i >= 0 ? p5[i] : -p5[-i]);
            ll val2 = (j >= 0 ? p5[j] : -p5[-j]);
            if(val1 - val2 == x){
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
}
