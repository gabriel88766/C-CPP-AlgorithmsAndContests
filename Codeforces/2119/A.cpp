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
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if(a == b) cout << "0\n";
        else if((a^1) == b && a + 1 != b) cout << y << "\n";
        else if(a > b) cout << "-1\n";
        else{
            int ans = 0;
            for(int i=a;i<b;i++){
                if(i & 1) ans += x;
                else ans += min(x, y);
            }
            cout << ans << "\n";
        }
    }
}
