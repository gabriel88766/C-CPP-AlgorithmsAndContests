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
        int n;
        string s;
        cin >> n >> s;
        bool ok = false;
        if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') ok = true;
        if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n-1] == '0') ok = true;
        if(s[0] == '2' && s[1] == '0' && s[n-2] == '2' && s[n-1] == '0') ok = true;
        if(s[0] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0') ok = true;
        if(s[n-4] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0') ok = true;
        if(ok) cout << "YES\n";
        else cout <<  "NO\n";
    }
}
