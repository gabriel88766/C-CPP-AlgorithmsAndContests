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
    int n, p;
    cin >> n >> p;
    bool ok = true;
    for(int i=1;i<=32;i++){
        n -= p;
        if(n < 0){
            ok = false;
            break;
        }
        if(__builtin_popcount(n) <= i && n >= i){
            cout << i;
            break;
        }
    }
    if(!ok) cout << -1;
}
