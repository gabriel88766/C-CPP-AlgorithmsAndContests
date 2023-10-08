#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll n, m;
ll v[N];
ll ans[N];
ll f[N];
pair<ll, ll> w[N];
void dc(int l, int r, int opl, int opr){
    if(l > r) return;
    int mid = (l+r)/2;
    ll best = -1;
    int opm;
    for(ll i=opl;i<=opr;i++){
        if(f[i] + w[mid].first * (n-i) > best){
            best = f[i] + w[mid].first * (n-i);
            opm = i;
        }
    }
    ans[w[mid].second] = best;
    dc(l, mid-1, opl, opm);
    dc(mid+1, r, opm, opr);
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v, v + n);
    for(ll i=0;i<n;i++){
        f[i] = v[i] * (n-i);
    }
    for(int i=0;i<m;i++){
        cin >> w[i].first;
        w[i].second = i;
    }
    sort(w, w+m, greater<pair<ll,ll>>());
    dc(0, m-1, 0, n-1);
    for(int i=0;i<m;i++) cout << ans[i] << " ";

}
