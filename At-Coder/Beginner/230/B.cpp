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
    string t = "oxx";
    cin >> s;
    bool ok = false;
    for(int i=0;i<3;i++){
        bool cok = true;
        int p = i;
        for(int j=0;j<s.size();j++){
            if(s[j] != t[p]) cok = false;
            p = (p + 1) % 3;
        }  
        if(cok) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
