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
    ll r, x, y;
    cin >> r >> x >> y;
    if(r*r == x*x+y*y) cout << "1\n";
    else{
        for(ll i=2;i<=200000;i++){
            if(i*i*r*r >= x*x + y*y){
                cout << i << "\n";
                break;
            }
        }
    }
}
