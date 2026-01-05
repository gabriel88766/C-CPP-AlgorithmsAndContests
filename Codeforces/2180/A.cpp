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
        int l, a, b;
        cin >> l >> a >> b;
        vector<bool> vx(l, false);
        int ans = a;
        int cur = a;
        while(!vx[cur]){
            vx[cur] = true;
            cur = (cur + b) % l;
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}
