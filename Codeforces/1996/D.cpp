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
        int n, x;
        cin >> n >> x;
        ll ans = 0;
        for(int a=1;a<=n;a++){
            for(int b=1;a*b<=n;b++){
                int cmx = x - a - b;
                if(cmx <= 0) break;
                //a+b+c <= x ok
                int cmx2 = (n - a*b)/(a+b);
                ans += min(cmx, cmx2);
            }
        }
        cout << ans << "\n";
    }
}
