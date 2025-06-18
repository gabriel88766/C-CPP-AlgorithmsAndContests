#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    double ans = 0;
    for(int i=1;i<=n;i++){
        double x;
        string s;
        cin >> x >> s;
        if(s == "JPY") ans += x;
        else ans += 380000.0 * x;
    }
    cout << fixed << setprecision(6) << ans << "\n";
}
