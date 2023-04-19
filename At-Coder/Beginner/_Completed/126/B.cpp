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
    bool ok1 = false, ok2 = false;
    string s;
    cin >> s;
    if((s[0] == '0' && s[1] != '0') || (s[0] == '1' && s[1] <= '2')) ok1 = true;
    if((s[2] == '0' && s[3] != '0') || (s[2] == '1' && s[3] <= '2')) ok2 = true;
    if(ok1 && ok2) cout << "AMBIGUOUS\n";
    else if(ok1) cout << "MMYY\n";
    else if(ok2) cout << "YYMM\n";
    else cout << "NA\n";
}
