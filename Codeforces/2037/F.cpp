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
        vector<ll> h(n), x(n);
        for(int i=0;i<n;i++) cin >> h[i];
        for(int i=0;i<n;i++) cin >> x[i];
        ll lo = 1, hi = 1'000'000'001;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            vector<pair<ll,ll>> evt;
            for(int i=0;i<n;i++){
                ll mn = (h[i] + mid - 1)/mid;
                if(mn > m) continue;
                else{
                    evt.push_back({x[i] - (m - mn), 1});
                    evt.push_back({x[i] + (m - mn) + 1, -1});
                }
            }
            int mv = 0, cur = 0;
            sort(evt.begin(), evt.end());
            int p = 0;
            while(p < evt.size()){
                int curv = evt[p].first;
                while(p < evt.size() && evt[p].first == curv){
                    cur += evt[p].second;
                    p++;
                }
                mv = max(mv, cur);
            }
            if(mv >= k) hi = mid;
            else lo = mid + 1;
        }
        if(lo == 1'000'000'001) lo = -1;
        cout << lo << "\n";
    }
}
