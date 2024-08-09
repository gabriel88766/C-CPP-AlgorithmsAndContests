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
    int a, x, y;
    cin >> a >> x >> y;
    if(!(y%a)) cout << "-1\n";    
    else{
        if(y < a){
            if(abs(x) < a/2 + a%2) cout << 1 << "\n";
            else cout << "-1\n";
        }else{
            y -= a;
            int bg = 2;
            while(y > 2*a){
                y -= 2*a;
                bg += 3;
            }
            if(y < a){
                if(abs(x) < a/2 + a%2) cout << bg << "\n";
                else cout << "-1\n";
            }else{
                y -= a;
                if(x != 0 && abs(x) < a){
                    if(x < 0) cout << bg + 1 << "\n";
                    else cout << bg + 2 << "\n";
                }else cout << "-1\n";
            }
        }
    }
}
