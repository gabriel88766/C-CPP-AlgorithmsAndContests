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
    freopen("out", "w", stdout); //test input
    cout << 2016 << "\n";
    for(int i=1;i<=63;i++){
        for(int j=i;j<=63;j++){
            int ans = 0;
            for(int k=1;k<=63;k++){
                int mn = INF_INT, mx = -1;
                for(int u=i;u<=j;u++){
                    mn = min(mn, k^u);
                    mx = max(mx, k^u);
                }
                if(mn == i && mx == j) ans++;
            }
            cout << i << " " << j << " " << ans << "\n";
        }
    }
}
