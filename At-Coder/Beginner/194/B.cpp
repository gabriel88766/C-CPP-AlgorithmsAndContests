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
    int ma = INF_INT, mb = INF_INT, ans = INF_INT;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        ans = min({ans, a + b, max(ma, b), max(a, mb)});
        ma = min(ma, a);
        mb = min(mb, b);
    }
    cout << ans << "\n";
}
