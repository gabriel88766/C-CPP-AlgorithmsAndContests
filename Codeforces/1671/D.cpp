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
        ll n, x;
        cin >> n >> x;
        ll ans = 0;
        ll m1 = INF_INT, mx = INF_INT, m1x = INF_INT;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=2;i<=n;i++) ans += abs(v[i] - v[i-1]);
        m1 = min(m1, abs(1 - v[1]));
        mx = min(mx, abs(x - v[1]));
        m1 = min(m1, abs(1 - v[n]));
        mx = min(mx, abs(x - v[n]));
        m1x = min(m1x, min(x-1 + abs(v[1] - x), x-1 + abs(v[1] - 1)));
        m1x = min(m1x, min(x-1 + abs(v[n] - x), x-1 + abs(v[n] - 1)));
        for(int i=2;i<=n;i++){
            m1 = min(m1, 2*abs(min(v[i], v[i-1]) - 1));
            if(min(v[i], v[i-1]) > x) mx = min(mx, 2*(min(v[i], v[i-1]) - x));
            else if(max(v[i], v[i-1]) < x) mx = min(mx, 2*(x - max(v[i], v[i-1])));
            else mx = 0;
            m1x = min(m1x, min(abs(1 - v[i-1]) + abs(x - 1) + abs(v[i] - x), abs(x - v[i-1]) + abs(x - 1) + abs(v[i] - 1)) - abs(v[i] - v[i-1]));
        }
        ans += min(m1 + mx, m1x);
        cout << ans << "\n";

    }
}
