#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, a, b, ans = -INF_LL;

    cin >> n >> a >> b;
    vector<ll> v(n+1);
    vector<ll> ps(n+1, 0);

    for(int i=1;i<=n;i++) {
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
    }

    set<pair<ll,ll>> setps;

    for(int i = 1; i <= n; i++){
        if(i >= a){
            setps.insert({ps[i-a], i-a});
        }
        if(i > b){
            setps.erase({ps[i-b-1], i-b-1});
        }
        if(setps.size() == 0) continue;
        auto it = setps.begin();
        ans = max(ans, ps[i] - it->first);
    }

    cout << ans;
}
