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
    bool ok1 = false, ok2 = false, ok3 = false;
    for(int i=0;i<3;i++){
        if(s[i] == 'a') ok1 = true;
        if(s[i] == 'b') ok2 = true;
        if(s[i] == 'c') ok3 = true;
    }
    if(ok1 && ok2 && ok3) cout << "Yes\n";
    else cout << "No\n";
}
