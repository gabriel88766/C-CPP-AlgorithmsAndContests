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
    int m, d;
    cin >> m >> d;
    bool ok = false;
    if(m == 1 && d == 7) ok = true;
    if(m == 3 && d == 3) ok = true;
    if(m == 5 && d == 5) ok = true;
    if(m == 7 && d == 7) ok = true;
    if(m == 9 && d == 9) ok = true;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
