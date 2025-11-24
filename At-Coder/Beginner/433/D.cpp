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
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    auto v2 = v;
    ll ans = 0;
    for(int i=1;i<=10;i++){
        for(auto &x : v2){
            x = (x * 10) % m;
        }
        sort(v2.begin(), v2.end());
        for(auto x : v){
            auto str = to_string(x);
            if(str.size() == i){
                ll gv = (m - (x % m)) % m;
                ans += upper_bound(v2.begin(), v2.end(), gv) - lower_bound(v2.begin(), v2.end(), gv);
            }
        }
    }
    cout << ans << "\n";
}
