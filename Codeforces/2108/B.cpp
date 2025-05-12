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
        if(n == 1){
            if(x > 0) cout << x << "\n";
            else cout << "-1\n";
        }else{
            int ppc = __builtin_popcount(x);
            if(ppc >= n) cout << x << "\n";
            else{
                int r = n - ppc;
                if(r % 2 == 0) cout << x + r << "\n";
                else{
                    if(ppc >= 2) cout << x + r + 1 << "\n";
                    else if(ppc == 1){
                        if(x & 1) cout << x + 4 + (r-1) << "\n";
                        else cout << x + r + 1 << "\n";
                    }else{
                        //xorsum = 0
                        cout << n+3 << "\n";
                    }
                }
            }
        }
    }
}
