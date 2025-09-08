#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll ans = 0;
    set<ll> vis;
    for(int iii=0;iii<15;iii++){
        int j = uniform_int_distribution<int>(0, n-1)(rng);
        ll cn = v[j];
        if(vis.count(cn)) continue;
        vis.insert(cn);
        vector<ll> ad;
        for(ll i=1;i*i<=cn;i++){
            if(cn % i == 0){
                ad.push_back(i);
                if(i*i != cn) ad.push_back(cn/i);
            }
        }
        vector<int> cnt(ad.size());
        sort(ad.begin(), ad.end());

        for(int k=0;k<n;k++){
            ll g = gcd(v[k], v[j]);
            int pl = lower_bound(ad.begin(), ad.end(), g) - ad.begin();
            cnt[pl]++;
        }
        for(int k=ad.size()-1;k>=0;k--){
            int cur = 0;
            for(int u=ad.size()-1;u>=k;u--){
                if(ad[u] % ad[k] == 0) cur += cnt[u];
            }
            if(2*cur >= n){
                ans = max(ans, ad[k]);
                break;
            }
        }
    }
    cout << ans << "\n";
}
