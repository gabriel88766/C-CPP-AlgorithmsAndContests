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
        int a, b, c;
        cin >> a >> b >> c;
        if(a < b) swap(a, b);
        if(a < c) swap(a, c);
        if(b < c) swap(b, c);
        if(a == b + c) cout << "YES\n";
        else if(b == c && (!(a % 2))) cout << "YES\n";
        else if(a == b && (!(c % 2))) cout << "YES\n";
        else cout << "NO\n";
    }
}