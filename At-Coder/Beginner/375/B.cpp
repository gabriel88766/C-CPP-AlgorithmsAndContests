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
    vector<pair<int,int>> vp;
    vp.push_back({0, 0});
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    vp.push_back({0, 0});
    double ans = 0;
    for(int i=1;i<vp.size();i++){
        auto [a, b] = vp[i];
        auto [c, d] = vp[i-1];
        ll dx = abs(a-c);
        ll dy = abs(b-d);
        ans += sqrt(dx*dx+dy*dy);
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
