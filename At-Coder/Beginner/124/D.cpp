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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "1" + s + "0";
    int p1 = 0, p2 = 0, cur = 0, ans = 0;
    while(p1 < n){
        if(cur <= k){
            if(p2 == n + 1) break;
            while(p2 <= n){
                p2++;
                if(s[p2] == '0' && s[p2-1] == '1') cur++;
                if(cur > k) break;
            }
            
        }else{
            while(p1 <= n && s[p1] == '1') p1++;
            while(p1 <= n && s[p1] == '0') p1++;
            cur--;
        }
        if(p1 == 0) ans = max(ans, p2-1);
        else ans = max(ans, p2-p1);
    }
    cout << ans << "\n";
}
