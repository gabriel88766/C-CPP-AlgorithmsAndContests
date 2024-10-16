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
        vector<pair<ll,ll>> vp(n+1);
        for(int i=1;i<=n;i++){
            cin >> vp[i].first >> vp[i].second;
        }
        tuple<ll,ll,ll> cp = {0, 0, 0}; //source, destination, time departs
        ll ans = 0;
        for(int i=1;i<=n;i++){
            auto [s, d, t] = cp;
            auto [tm, dd] = vp[i];
            ll nt = i == n ? INF_LL : vp[i+1].first;
            if(tm >= t + abs(d-s)){
                s = d;
                d = dd;
                t = tm;
                cp = {s, d, t};
            }
            //now check if i can pass dd between tm and nt
            ll cx = s + ((d-s) >= 0 ?  (tm - t) : t - tm);
            ll fx = s + ((d-s) >= 0 ?  min(nt-t, d-s) : max(t - nt, d - s));
            // cout << cx << " " << fx << " " << dd << "\n";
            if(min(cx,fx) <= dd && max(cx,fx) >= dd) ans++;
        }
        cout << ans << "\n";
    }
}
