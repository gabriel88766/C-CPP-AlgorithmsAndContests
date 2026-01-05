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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    int ans = INF_INT;
    for(int i=0;i<=n-m;i++){
        int cur = 0;
        for(int j=0;j<m;j++){
            if(s[i+j] >= t[j]) cur += s[i+j] - t[j];
            else cur += 10 - (t[j] - s[i+j]);
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}
