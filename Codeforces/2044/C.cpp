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
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int m1, m2, m3;
        m1 = min(a, m);
        m2 = min(b, m);
        m3 = min(2*m - m1 - m2, c);
        cout << m1+m2+m3 << "\n";
    }
}
