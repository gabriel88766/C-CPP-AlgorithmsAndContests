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
    int t;
    cin >> t;
    while(t--){
        ll n, g, b;
        cin >> n >> g >> b;
        ll mb = n/2;
        ll mg = n - mb;
        ll td1 = ((mg-1)/ g) * (g+b) + (mg - 1) % g + 1;
        cout << max(td1, n) << "\n"; 
    }
}
