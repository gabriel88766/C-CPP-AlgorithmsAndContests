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
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    if(k >= a){
        ans += a;
        k -= a;
    }else{
        ans += k;
        k = 0;
    }
    if(k >= b){
        k -= b;
    }else{
        k = 0;
    }
    if(k >= c){
        ans -= c;
        k -= c;
    }else{
        ans -= k;
        k = 0;
    }
    cout << ans << "\n";
}
