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
    cin >> n;
    int x = 0;
    for(int i=0;i<n;i++){
        int y;
        cin >> y;
        x += y;
    }
    cin >> m;
    int ans = INF_INT;
    for(int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        if(x <= r) ans = min(ans, max(l, x));
    }
    if(ans == INF_INT) ans = -1;
    cout << ans << "\n";
}
