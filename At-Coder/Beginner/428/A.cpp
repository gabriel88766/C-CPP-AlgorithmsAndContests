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
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int cur = 0, ans = 0;
    int xx = 0;
    while(cur <= x){
        if(xx){
            cur += b;
        }else{
            int dif = min(a, x - cur);
            ans += dif * s;
            cur += a;
        }
        xx ^= 1;
    }
    cout << ans << "\n";
}
