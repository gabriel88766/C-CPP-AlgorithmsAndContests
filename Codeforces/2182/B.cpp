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
        int a, b;
        cin >> a >> b;
        int ans = 0;
        int ca = a, cb = b;
        for(int i=0;;i++){
            int cj = 1 << i;
            if(i % 2){
                if(ca >= cj) ca -= cj;
                else{
                    ans = max(ans, i);
                    break;
                }
            }else{
                if(cb >= cj) cb -= cj;
                else{
                    ans = max(ans, i);
                    break;
                }
            }
        }
        ca = a, cb = b;
        for(int i=0;;i++){
            int cj = 1 << i;
            if((i % 2) == 0){
                if(ca >= cj) ca -= cj;
                else{
                    ans = max(ans, i);
                    break;
                }
            }else{
                if(cb >= cj) cb -= cj;
                else{
                    ans = max(ans, i);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}
