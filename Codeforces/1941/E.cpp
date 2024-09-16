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
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        vector<ll> val(n);
        for(int i=0;i<n;i++){
            deque<pair<ll,ll>> dq;
            ll x;
            dq.push_back({1, 0});
            cin >> x;
            for(int j=1;j<m;j++){
                cin >> x;
                ll cur = dq.front().first + x + 1;
                while(cur <= dq.back().first) dq.pop_back();
                dq.push_back({cur, j});
                if(j - dq.front().second == d + 1) dq.pop_front(); 
            }
            val[i] = dq.back().first;
        }
        ll ans = INF_LL;
        for(int i=0;i<=n-k;i++){
            ll cur = 0;
            for(int j=0;j<k;j++) cur += val[i+j];
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
}
