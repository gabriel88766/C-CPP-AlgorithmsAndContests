#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<string> v = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    int ans = 0;
    while(t--){
        string s;
        cin >> s;
        for(int i=0;i<v.size();i++){
            if(s == v[i]) ans++;
        }
        if(s.size() <= 1){
            if('0' <= s[0] && '9' >= s[0]) ans++;
        }
        if(s.size() <= 2){
            if(s[0] == '1' && s[1] >= '0' && s[1] <= '7') ans++;
        }
    }
    cout << ans << "\n";
}
