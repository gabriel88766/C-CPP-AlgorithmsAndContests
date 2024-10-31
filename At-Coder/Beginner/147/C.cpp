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
    vector<vector<pair<int,int>>> vp(n);
    for(int i=0;i<n;i++){
        int sz;
        cin >> sz;
        for(int j=0;j<sz;j++){
            int x, y;
            cin >> x >> y;
            x--;
            vp[i].push_back({x, y});
        }
    }
    int ans = 0;
    for(int i=0;i<(1 << n);i++){
        bool ok = true;
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                //j is honest
                for(int k=0;k<vp[j].size();k++){
                    auto [x, y] = vp[j][k];
                    int b = (i & (1 << x)) >> x;
                    if(b != y) ok = false;
                }
            }
        }
        if(ok) ans = max(ans, __builtin_popcount(i));
    }
    cout << ans << "\n";
}
