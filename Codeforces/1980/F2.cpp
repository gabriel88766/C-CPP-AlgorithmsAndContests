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
        vector<fo> vp(k+1);
        for(int i=0;i<k;i++){
            ll a, b;
            cin >> a >> b;
            vp[i] = {a, b, i};
        }
        vp[k] = {n, m+1, -1};
        sort(vp.begin(), vp.end());
        
        ll ans = 0;
        vector<ll> ansv(k);
        ll hi = 0;
        vector<int> chk;
        for(int i=0;i<=k;i++){
            if(vp[i].r > hi){
                ans += (vp[i].r - hi) * (vp[i].c - 1);
                hi = vp[i].r;
                chk.push_back(i);
            }
        }
        if(chk.back() != k) chk.push_back(k);
        hi = 0;
        for(int i=0;i<chk.size()-1;i++){
            int i1 = chk[i], i2 = chk[i+1];
            ll ans1 = (vp[i1].r - hi) * (vp[i1].c - 1);
            ans1 += (vp[i2].r - vp[i1].r) * (vp[i2].c - 1);
            ll ans2 = 0;
            ll hi2 = hi;
            for(int j=i1+1;j<=i2;j++){
                if(vp[j].r > hi2){
                    ans2 += (vp[j].r - hi2) * (vp[j].c - 1);
                    hi2 = vp[j].r;
                }
            }
            ansv[vp[i1].i] = ans2 - ans1;
            hi = vp[i1].r;
        }
        cout << ans << "\n";
        for(auto x : ansv) cout << x << " ";
        cout << "\n";

    }
}
