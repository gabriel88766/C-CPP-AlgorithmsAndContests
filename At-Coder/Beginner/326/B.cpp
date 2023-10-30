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
    int n;
    cin >> n;
    while(n <= 919){
        int c,d,u;
        int aux = n;
        u = aux % 10;
        aux /= 10;
        d = aux % 10;
        aux /= 10;
        c = aux % 10;
        if(c*d == u){
            cout << n << "\n";
            break;
        }else ++n;
    }
}
