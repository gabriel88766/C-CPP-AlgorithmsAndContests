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
    ll n, m, d;
    cin >> n >> m >> d;
    ll hf = n/2;
    vector<ll> r(m+2), s(m+1);
    vector<ll> ansd(d+1);
    for(int i=0;i<=m;i++) cin >> r[i];
    for(int i=0;i<m;i++) cin >> s[i];
    s[m] = 0;
    r[0] = -1;
    r[m+1] = INF_LL;
    vector<pair<ll, ll>> vp;
    ll aux = 0;
    for(ll i=0;i<hf;i++){
        ll pos = i*d;
        int ind = lower_bound(r.begin(), r.end(), pos) - r.begin();
        aux += s[ind-1];
        for(int j=ind;;j++){
            if(r[j] - pos < d){
                vp.push_back({r[j]-pos+1, s[j] - s[j-1]});
            }else break;
        }
    }
    sort(vp.begin(), vp.end());
    int p = 0;
    for(int i=0;i<=d;i++){
        while(p < vp.size() && vp[p].first == i){
            aux += vp[p++].second;
        }
        ansd[i] = aux;
    }
    ll ans = 0;
    for(int i=0;i<=d/2;i++){
        ll cur = ansd[i] + ansd[d-i];
        if(n % 2){
            ll lp = hf * d + i;
            int ind = lower_bound(r.begin(), r.end(), lp) - r.begin();
            cur += s[ind-1];
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
