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
        vector<pair<ll, ll>> obx, oby;
        vector<pair<ll, ll>> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first >> v[i].second;
            obx.push_back({v[i].first, v[i].second});
            oby.push_back({v[i].second, v[i].first});
        }
        if(n == 1){
            cout << "1\n";
            continue;
        }

        sort(obx.begin(), obx.end());
        sort(oby.begin(), oby.end());
        ll ans = INF_LL;
        for(int i=0;i<n;i++){
            int x0 = 0, x1 = n-1;
            int y0 = 0, y1 = n-1;
            if(obx[x0] == v[i]) x0++;
            if(obx[x1] == v[i]) x1--;
            if(make_pair(oby[y0].second, oby[y0].first) == v[i]) y0++;
            if(make_pair(oby[y1].second, oby[y1].first) == v[i]) y1--;
            ll xv = obx[x1].first - obx[x0].first + 1;
            ll yv = oby[y1].first - oby[y0].first + 1;
            // cout << xv << " " << yv << "\n";
            if(xv*yv >= n) ans = min(ans, xv*yv);
            else ans = min({ans, (xv+1)*yv, xv*(yv+1)});
        }
        cout << ans << "\n";
    }
}
