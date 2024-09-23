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
        ll n, m, k;
        cin >> n >> m >> k;
        vector<pair<ll, ll>> vp;
        for(int i=0;i<n;i++){
            ll a, b;
            cin >> a >> b;
            vp.emplace_back(a, b);
        }
        ll cd = 0, ans = 0, p = 0;
        vector<pair<ll,ll>> vx;
        while(vx.size() || p < vp.size()){
            if(vx.empty()){
                cd = vp[p].first;
                vx.push_back(vp[p]);
                p++;
            }
            if(p < vp.size() && cd == vp[p].first){
                vx.push_back(vp[p]);
                p++;
            }
            auto [d, a] = vx.back();
            vx.pop_back();
            if(a < m){
                if(vx.size()){
                    vx.back().second += a;
                }
                continue;
            }
            ll dpx = (p == n ? INF_LL : vp[p].first - 1);
            ll dpk = d + k - 1;
            ll de = cd + a/m - 1;
            if(de <= dpx){
                if(dpk <= de){
                    vx.clear();
                    ll x = max((dpk - cd + 1), 0LL);
                    ans += x;
                }else{
                    ans += a/m;
                    ll qnt = a - (a/m) * m;
                    cd += a/m;
                    vx.push_back({d, qnt});
                }
            }else{
                //this case, all next days [cd, dpx] will be good
                ll qd = min(dpx, dpk) - cd + 1;
                qd = max(qd, 0LL);
                ans += qd;
                cd = cd + qd;
                if(dpk <= dpx){
                    vx.clear();
                }else{
                    vx.push_back({d, a - m*qd});
                }
            }
        }

        cout << ans << "\n";

    }
}
