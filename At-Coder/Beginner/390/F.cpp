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
    cin >> n;
    vector<vector<ll>> pl(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        pl[x].push_back(i);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<pl[i].size();j++){
            auto it = lower_bound(pl[i-1].begin(), pl[i-1].end(), pl[i][j]);
            ll mn = 1, mx = n;
            if(j > 0) mn = max(mn, pl[i][j-1] + 1);
            if(it != pl[i-1].end()) mx = min(mx, *it - 1);
            if(it != pl[i-1].begin()) mn = max(mn, *prev(it) + 1);
            ans += (pl[i][j] - mn + 1) * (mx - pl[i][j] + 1);
        }
    }
    cout << ans << "\n";
}
