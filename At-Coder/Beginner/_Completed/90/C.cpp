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
    ll a, b;
    cin >> a >> b;
    if(a == 1 && b == 1) cout << "1\n";
    else if(a == 1) cout << b-2 << "\n";
    else if(b == 1) cout << a-2 << "\n";
    else cout << (a-2)*(b-2) << "\n";
}
