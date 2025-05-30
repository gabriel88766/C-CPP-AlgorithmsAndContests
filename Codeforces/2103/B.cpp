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
        int ans = 0;
        string s;
        int n;
        cin >> n >> s;
        s = "0" + s;
        for(int i=1;i<s.size();i++){
            if(s[i] != s[i-1]) ans++;
        }
        if(ans >= 3) ans -= 2;
        else if(ans == 2) ans -= 1;
        ans += n;
        cout << ans << "\n";
    }
}
