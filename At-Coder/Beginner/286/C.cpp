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
    ll n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    ll cst = INF_LL;
    ll cur = 0;
    for(int i=0;i<n;i++){
        ll cc = cur;
        for(int j=0;j<n/2;j++) if(s[j] != s[n-j-1]) cc += b;
        cst = min(cst, cc);
        cur += a;
        s = s.substr(1, s.size() - 1) + s[0];
        // cout << s << "\n";
    }   
    cout << cst << "\n";
}
