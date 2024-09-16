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
        int h, w, xa, ya, xb, yb;
        cin >> h >> w >> xa >> ya >> xb >> yb;
        if(xb < xa) cout << "Draw\n";
        else{
            int dif = abs(xa - xb);
            if(dif % 2){
                //alice or draw
                if(abs(ya - yb) <= 1) cout << "Alice\n";
                else if(ya < yb){
                    int ga = (dif + 1)/2  + ya;
                    if(ga >= w) cout << "Alice\n";
                    else cout << "Draw\n";
                }else{
                    int ga = ya - (dif + 1)/2;
                    if(ga <= 1) cout << "Alice\n";
                    else cout << "Draw\n";
                }
            }else{
                //bob or draw
                if(ya == yb) cout << "Bob\n";
                else if(ya < yb){
                    int gb = yb - dif/2;
                    if(gb <= 1) cout << "Bob\n";
                    else cout << "Draw\n";
                }else{
                    int gb = yb + dif/2;
                    if(gb >= w) cout << "Bob\n";
                    else cout << "Draw\n";
                }
            }
        }
    }
}
