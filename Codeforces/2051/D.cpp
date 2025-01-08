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
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll S = 0;
        for(int i=0;i<n;i++) S += v[i];
        ll ans = 0;
        for(int i=0;i<n;i++){
            //S - ?? - v[i] >= x -> ?? <= S - x - v[i] && ?? >= S - y - v[i];
            ll xmin = S - y - v[i];
            ll xmax = S - x - v[i];
            auto it1 = lower_bound(v.begin(), v.end(), xmin);
            auto it2 = upper_bound(v.begin(), v.end(), xmax);
            ans += it2 - it1;
            if(xmin <= v[i] && xmax >= v[i]) ans--;
        }
        ans /= 2;
        cout << ans << "\n";
    }
}
