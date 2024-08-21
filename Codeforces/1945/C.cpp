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
        s = " " + s;
        int cr = 0, cl = 0;
        int ans = -1;
        for(int i=1;i<=n;i++) if(s[i] == '1') cr++;
        if(cr >= n-cr) ans = 0;
        for(int i=1;i<=n;i++){
            if(s[i] == '1') cr--;
            if(s[i] == '0') cl++;
            int j = n - i;
            if(cl >= i-cl && cr >= j - cr){
                if(abs(n/2.0 - i) < abs(n/2.0 - ans)) ans = i;
            }
        }
        cout << ans << "\n";
    }
}
