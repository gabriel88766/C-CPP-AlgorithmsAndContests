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
        int n, s;
        cin >> n >> s;
        int ans = 0;
        for(int i=1;i<=n;i++){
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            if(dx > 0){
                x = s-x;
            }
            if(dy > 0){
                y = s-y;
            }
            if(x == y) ans++;
        }
        cout << ans << "\n";
    }
}
