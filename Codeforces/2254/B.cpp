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
        int ans = 1;
        for(int i=1;i<n;i++){
            if(s[i] != s[i-1]) ans++;
        }
        bool ok2 = false, ok1 = false;
        for(int i=1;i<n-1;i++){
            if(s[i] != s[i-1] && s[i-1] == s[i+1]) ok2 = true;
            if(s[i] != s[i-1] && s[i] != s[i+1]) ok1 = true;
        }
        if(ok2) ans -= 2;
        else if(ok1) ans -= 1;
        cout << ans << "\n";
    }
}
