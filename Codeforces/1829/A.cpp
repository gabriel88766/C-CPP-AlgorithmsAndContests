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
    string comp = "codeforces";
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        string s;
        cin >> s;
        for(int i=0;i<10;i++) if(s[i] != comp[i]) ans++;
        cout << ans << "\n";
    }
}
