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
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    //a < b < c
    if(a == 1 || b == 1 || c == 1) cout << "YES\n";
    else{
        if(a == 2 && b == 2) cout << "YES\n";
        else if(a == 2 && b == 4 && c == 4) cout << "YES\n";
        else if(a == 2 && b >= 4) cout << "NO\n";
        else if(a == 2 && b == 3) cout << "NO\n";
        else if(a == 3 && c == 3) cout << "YES\n";
        else cout << "NO\n";
    }
}
