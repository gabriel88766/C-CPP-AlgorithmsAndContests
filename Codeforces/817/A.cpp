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
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x, y;
    cin >> x >> y;
    int dif1 = abs(x1 - x2);
    int dif2 = abs(y1 - y2);
    if(dif1 % x || dif2 % y){
        cout << "NO\n";
    }else if(dif1/x % 2 != dif2/y % 2){
        cout << "NO\n";
    }else cout << "YES\n";
}
