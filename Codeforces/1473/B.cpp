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
    int q;
    cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        int p = 0;
        int tsz = lcm(s.size(), t.size());
        string ans;
        for(int i=0;i<tsz;i++){
            if(s[i%s.size()] == t[i%t.size()]) ans += s[i%s.size()];
            else{
                ans = "-1";
                break;
            }
        }
        cout << ans << "\n";
    }
}
