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
        ll n2, n3, n4;
        cin >> n2 >> n3 >> n4;
        n3 /= 2; //actually n6 now
        ll ans = 0;
        if(n3 <= n4){
            ans += n3;
            n4 -= n3;
            if(n4 / 2 >= n2){
                ans += n2;
            }else{
                n2 += 2*n4;
                ans += n2/5;
            }
        }else{
            ans += n4;
            n3 -= n4;
            n4 = 0;
            if(n2 / 2 >= n3){
                ans += n3;
                n2 -= 2*n3;
            }else{
                ans += n2 / 2;
                n2 = 0;
            }
            ans += n2 / 5;
        }
        cout << ans << "\n";

    }
}
