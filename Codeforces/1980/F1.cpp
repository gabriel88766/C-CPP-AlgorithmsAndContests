#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct fo{
    ll r, c, i;
    bool operator< (const fo &u) const{
        if( c != u.c) return c < u.c;
        else return r > u.r;
    }
};

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
        vector<fo> vp(k);
        for(int i=0;i<k;i++){
            ll a, b;
            cin >> a >> b;
            vp[i] = {a, b, i};
        }
        sort(vp.begin(), vp.end());
        ll ans = 0;
        vector<ll> ansv(k);
        ll hi = 0, mw = 0;
        for(int i=0;i<k;i++){
            if(vp[i].r > hi){
                ans += (vp[i].r - hi) * (vp[i].c - 1);
                hi = vp[i].r;
                ansv[vp[i].i] = 1;
            }
        }
        ans += (n - hi) * m;
        cout << ans << "\n";
        for(auto x : ansv) cout << x << " ";
        cout << "\n";

    }
}
