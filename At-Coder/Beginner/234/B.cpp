#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    double ans = 0;
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].first >> vp[i].second;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x = abs(vp[i].first - vp[j].first);
            int y = abs(vp[i].second - vp[j].second);
            ans = max(ans, sqrt(x*x+y*y));
        }
    }



    cout << fixed << setprecision(15) << ans << "\n";
}
