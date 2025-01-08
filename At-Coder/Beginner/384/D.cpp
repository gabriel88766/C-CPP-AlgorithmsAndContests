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
    int n;
    ll S;
    cin >> n >> S;
    vector<ll> v(n+1), ps(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
    }
    ll r = S % ps[n];
    bool ok = false;
    for(int i=1;i<=n;i++){
        auto it = lower_bound(ps.begin(), ps.end(), r + ps[i-1]);
        if(it == ps.end()){
            ll nv = r - ps[n] + ps[i-1];
            assert(nv > 0);
            auto it2 = lower_bound(ps.begin(), ps.end(), nv);
            if(it2 != ps.end() && *it2 == nv) ok = true;
        }else if(*it == r + ps[i-1]) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";

}
