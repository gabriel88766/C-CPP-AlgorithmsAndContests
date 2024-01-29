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
    int b;
    cin >> b;
    int a1 = 0, a2 = 0, a3 = 0;
    while(a1 <= b){
        cout << a1 << " " << a2 << " " << a3 << "\n";
        a3++;
        if(a1 + a2 + a3 > b){
            a3 = 0;
            a2++;
        }
        if(a1 + a2 + a3 > b){
            a2 = 0;
            a1++;
        }
    }
}
