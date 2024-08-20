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
        string s;
        cin >> s;
        int ca = 0, cb = 0, cc = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'A') ca++;
            else if(s[i] == 'B') cb++;
            else cc++;
        }
        if(cb == ca + cc) cout << "YES\n";
        else cout << "NO\n";
    }
}
