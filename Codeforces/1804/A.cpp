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
        int a,b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        int ans = 2*min(a,b);
        int diff = max(a,b) - min(a,b);
        if(diff > 1){
            ans++;
            ans += (diff-1)*2;
        }else ans += diff;
        cout << ans << "\n";
    }
}
