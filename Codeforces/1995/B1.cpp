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
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> vp(n);
        for(int i=0;i<n;i++) cin >> vp[i].first;
        for(int i=0;i<n;i++) vp[i].second = 1; //change to cin
        sort(vp.begin(), vp.end());
        int p = 0;
        ll ans = 0;
        while(p < n){
            int p1 = p;
            while(p1+1 < n && vp[p1+1].first - vp[p].first <= 1) p1++;
            //range [p, p1]
            ll mnf = 0, cnt = 0, mxf = 0;
            for(int i=p;i<=p1;i++){
                ll cur = min((m-mnf)/vp[i].first, vp[i].second);
                mnf += cur * vp[i].first;
                cnt += cur;
            }
            for(int i=p1;i>=p;i--){
                ll cur = min(cnt, vp[i].second);
                mxf += cur * vp[i].first;
                cnt -= cur;
            }
            ans = max(ans, min(m, mxf));
            p = lower_bound(vp.begin(), vp.end(), make_pair(vp[p].first+1, -5LL)) - vp.begin();
        }
        cout << ans << "\n";
    }
}
