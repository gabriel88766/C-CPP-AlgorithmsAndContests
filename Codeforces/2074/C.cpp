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
        int x;
        cin >> x;
        int msb =  31 - __builtin_clz(x);
        int cz = 0, cnz = 0;
        for(int j=0;j<msb;j++){
            if(x & (1 << j)) cnz++;
            else cz++;
        }
        if(cz && cnz){
            cout << (1 << msb) - 1 << "\n";
        }else cout << "-1\n";
    }
}
