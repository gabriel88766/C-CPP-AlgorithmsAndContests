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
    int n;
    string s,t;
    cin >> n >> s >> t;
    ll ans = 0;
    for(int i=0;i<n/2;i++){
        int j = n-1-i;
        if((s[i] == t[i] && s[j] == t[j]) || (s[i] == t[j] && s[j] == t[i]) || (s[i] == s[j] && t[i] == t[j])) continue;
        if(t[i] == t[j] || s[i] == t[i] || s[i] == t[j] || s[j] == t[i] || s[j] == t[j]) ans+=1;
        else ans+=2;
    }
    if(n%2 && s[n/2] != t[n/2]) ans++;
    cout << ans;
}
