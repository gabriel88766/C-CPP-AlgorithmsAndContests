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
        string s,t;
        cin >> s >> t;
        if(size(s) < size(t)){
            int qt = size(t)-size(s);
            string x;
            for(int i=0;i<qt;i++) x += '0';
            s = x + s;
        }else{
            int qt = size(s)-size(t);
            string x;
            for(int i=0;i<qt;i++) x += '0';
            t = x + t;
        }
        int ind = 0;
        int sz = size(s);
        while(s[ind] == t[ind] && ind < sz) ind++;
        if(ind == sz) cout << "0\n";
        else{
            int ans = abs(s[ind]-t[ind]);
            ans += (sz-ind-1)*9;
            cout << ans << "\n";
        }
    }
}
