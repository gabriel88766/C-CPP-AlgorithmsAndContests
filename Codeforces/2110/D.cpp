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
        int n, m;
        cin >> n >> m;
        vector<ll> b(n+1);
        for(int i=1;i<=n;i++) cin >> b[i];
        vector<vector<pair<ll, ll>>> adj(n+1);
        for(int i=1;i<=m;i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
        }
        //cant do directly, lets bin search..
        ll lo = 0, hi = 1'000'000'001; //with high I can traverse all.
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            vector<ll> mx(n+1, -INF_LL);
            mx[1] = 0;
            for(int i=1;i<=n;i++){
                ll mxx = min(mid, mx[i] + b[i]);
                if(mxx < 0) continue;
                for(auto &[v, w] : adj[i]){
                    if(mxx >= w){
                        //can use;
                        mx[v] = max(mx[v], mxx);
                    }
                }
            }
            if(mx[n] >= 0) hi = mid;
            else lo = mid + 1;
        }
        if(lo == 1'000'000'001) cout << "-1\n";
        else cout << lo << "\n";


    }
}
