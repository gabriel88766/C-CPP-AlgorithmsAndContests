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
    ll n, m, l, y, x;
    cin >> n >> m >> l >> x >> y;
    vector<pair<int, int>> vp(n), oans(m);
    vector<double> ans(m);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    for(int i=0;i<m;i++){
        oans[i].second = i;
        cin >> oans[i].first;
    }
    sort(oans.begin(), oans.end());
    double cans = 1e30;
    for(auto [cx, j] : oans){
        cans = min(cans, (l - cx)/((double) y));
        while(vp.size() && vp.back().first <= cx){
            double st1 = (vp.back().second - vp.back().first) / ((double) x);
            double st2 = (l - vp.back().second) / ((double) y);
            cans = min(cans, st1 + st2);
            vp.pop_back();
        }
        ans[j] = cans;
    }
    for(int j=0;j<m;j++){
        cout << fixed << setprecision(10) << ans[j] << "\n";
    }
}
