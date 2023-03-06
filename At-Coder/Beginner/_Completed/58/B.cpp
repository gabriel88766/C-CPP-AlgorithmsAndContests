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
    //freopen("in", "r", stdin); test input
    int bp1=0, bp2=0, i = 0;
    string s, t, ans;
    cin >> s >> t;
    while(bp1 < s.size() || bp2 < t.size()){
        if(i%2) ans += t[bp2++];
        else ans += s[bp1++]; 
        i++;
    }
    cout << ans;
}
