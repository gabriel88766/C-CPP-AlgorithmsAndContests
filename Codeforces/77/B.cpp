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
        double a, b, ans;
        cin >> a >> b;
        if(a == 0 || b == 0){
            if(a == 0 && b != 0) ans = 0.5;
            else ans = 1;
        }else if(4*b <= a){
            ans = (a-4*b)/a + (2*b)/a + b/a;
        }else{
            ans = 0.5 + (a)/(16*b);
        }
        cout << fixed << setprecision(15) << ans << "\n";
    }
}
