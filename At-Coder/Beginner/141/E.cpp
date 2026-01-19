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
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int len = 1; len <= n; len++){
        int cur = 0;
        for(int i=0;i<n-len;i++){
            if(s[i] == s[i + len]) cur++;
            else cur = 0;
            ans = max(ans, min(len, cur));
        }
    }
    cout << ans << "\n";
}
