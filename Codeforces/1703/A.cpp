#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool ok = true;
        if(s[0] != 'y' && s[0] != 'Y') ok = false;
        if(s[1] != 'e' && s[1] != 'E') ok = false;
        if(s[2] != 's' && s[2] != 'S') ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
