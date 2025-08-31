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
    ll a, b, c;
    cin >> a >> b;
    for(int i=3;i<=10;i++){
        // int aux = a + b;
        string x = to_string(a+b);
        reverse(x.begin(), x.end());
        c = stoll(x);
        if(i == 10) cout << c << "\n";
        a = b;
        b = c;  
    }
}
