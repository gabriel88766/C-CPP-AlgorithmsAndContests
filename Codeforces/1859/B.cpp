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
        int n;
        cin >> n;
        vector<pair<ll,ll>> vp(n);
        for(int i=0;i<n;i++){
            int m;
            cin >> m;
            vector<int> v(m);
            for(int j=0;j<m;j++) cin >> v[j];
            sort(v.begin(), v.end());
            vp[i] = {v[0], v[1]};
        }
        ll S = 0;
        ll minv = INF_INT;
        ll minv2 = INF_INT;
        for(int i=0;i<n;i++) {S += vp[i].second; minv = min(minv, vp[i].first); minv2 = min(minv2, vp[i].second);}
        ll ans = S - minv2 + minv;
        cout << ans << "\n";
    }
}
