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
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll lc = 1;
        ll mx = *max_element(v.begin(), v.end());
        for(int i=0;i<n;i++){
            lc = lcm(lc, v[i]);
            if(lc > mx) break;
        }
        if(lc > mx) cout << n << "\n";
        else{
            ll ans = 0;
            //all numbers are divisors of maxn
            vector<ll> divs;
            //bad algo but may pass
            for(ll i=1;i*i<=mx;i++){
                if(!(mx % i)){
                    if(i*i != mx) divs.push_back(mx/i);
                    divs.push_back(i);
                }
            }
            for(auto &x : divs){
                auto it = lower_bound(v.begin(), v.end(), x);
                if(it != v.end() && *it == x) continue;
                ll lc = 1, cnt = 0;
                for(int j=0;j<n;j++){
                    if(!(x % v[j])){
                        cnt++;
                        lc = lcm(lc, v[j]);
                    }
                }
                if(lc == x) ans = max(ans, cnt);
            }
            cout << ans << "\n";
        }
    }
}
