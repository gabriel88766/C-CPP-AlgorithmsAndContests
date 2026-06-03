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
    int ans = 0;
    for(int i=100;i<=999;i++){
        for(int j=100;j<=999;j++){
            int cur = i * j;
            string s = to_string(cur);
            string rev = s;
            reverse(rev.begin(), rev.end());
            if(s == rev) ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
}
