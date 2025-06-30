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
    int cnt = 0;
    cin >> s;
    int ans = 0;
    for(int i=0;i<=9999;i++){
        string x = to_string(i);
        x = string(4-x.size(), '0') + x;
        string cs(10, 'x');
        for(int j=0;j<4;j++){
            cs[x[j]-'0'] = 'o'; 
        }
        bool cok = true;
        for(int j=0;j<=9;j++){
            if(s[j] == 'o' && cs[j] != 'o') cok = false;
            if(s[j] == 'x' && cs[j] != 'x') cok = false;
        }
        if(cok) ans++;
    }
    cout << ans << "\n";
}   
