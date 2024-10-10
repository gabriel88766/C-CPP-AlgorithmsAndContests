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
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int cs = 0, ans = 0;
    s += '*';
    for(int i=0;i<=n;i++){
        if(s[i] == '.') cs++;
        else{
            int mc = cs / 2;
            ans += min(mc, a) + min(mc, b);
            a -= min(mc, a);
            b -= min(mc, b);
            if(cs % 2){
                if(a > b){
                    a--;
                    ans++;
                }else if(b > 0){
                    b--;
                    ans++;
                }
            }
            cs = 0;
        }
    }
    cout << ans << "\n";
}
