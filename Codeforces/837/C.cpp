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
    cin >> n >> a >> b;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        vp[i] = {x, y};
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            auto [u, v] = vp[i];
            auto [x, y] = vp[j];
            int S = u*v + x*y;
            //try a, then try b
            vector<pair<int,int>> pos;
            pos.push_back({u+x, max(v, y)});
            pos.push_back({u+y, max(v, x)});
            pos.push_back({v+x, max(u, y)});
            pos.push_back({v+y, max(u, x)});
            for(auto [x, y] : pos){
                if(x <= a && y <= b) ans = max(ans, S);
                if(x <= b && y <= a) ans = max(ans, S);
            }
        }
    }
    cout << ans << "\n";
}
