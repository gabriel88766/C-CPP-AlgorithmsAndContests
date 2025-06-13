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
    string s;
    cin >> s;
    bool ok = true;
    if(s.size() == 8){
        if(s[0] < 'A' || s[0] > 'Z') ok = false;
        if(s[7] < 'A' || s[7] > 'Z') ok = false;
        for(int i=1;i<=6;i++) if(s[i] < '0' || s[i] > '9') ok = false;
        if(s[1] == '0') ok = false;
    }else ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
