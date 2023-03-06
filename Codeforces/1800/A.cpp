#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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
        int n;
        cin >> n >> s;
        int bp = 0;
        while(bp < n && s[bp] == 'm' || s[bp] == 'M') bp++;
        while(bp < n && s[bp] == 'e' || s[bp] == 'E') bp++;
        while(bp < n && s[bp] == 'o' || s[bp] == 'O') bp++;
        while(bp < n && s[bp] == 'w' || s[bp] == 'W') bp++;
        if(bp < n){
            cout << "NO\n";
            continue;
        }
        bool ok = true, ok2 = false;
        for(int i=0;i<n;i++) if(s[i] == 'm' || s[i] == 'M') ok2 = true;
        if(!ok2) ok = false;
        ok2 = false;
        for(int i=0;i<n;i++) if(s[i] == 'e' || s[i] == 'E') ok2 = true;
        if(!ok2) ok = false;
        ok2 = false;
        for(int i=0;i<n;i++) if(s[i] == 'o' || s[i] == 'O') ok2 = true;
        if(!ok2) ok = false;
        ok2 = false;
        for(int i=0;i<n;i++) if(s[i] == 'w' || s[i] == 'W') ok2 = true;
        if(!ok2) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
 