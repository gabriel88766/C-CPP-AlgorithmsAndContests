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
    cin >> n;
    vector<pair<int, int>> p(n);
    for(int i=1;i<=n;i++){
        cin >> p[i-1].first;
        p[i-1].second = i;
    }
    sort(p.begin(), p.end(), greater<pair<int, int>>());
    set<int> vis;
    ll ans = 0;
    for(auto [val, i] : p){
        auto it = vis.lower_bound(i);
        ll fl1 = n+1, fl2 = n+1;
        ll ll1 = 0, ll2 = 0;
        if(it != vis.end()){
            fl1 = *it;
            if(next(it) != vis.end()) fl2 = *next(it);
        }
        if(it != vis.begin()){
            ll1 = *prev(it);
            if(prev(it) != vis.begin()) ll2 = *prev(prev(it));
        }
        vis.insert(i);
        ll cur = (fl2 - fl1) * (i - ll1) + (ll1 - ll2) * (fl1 - i);
        ans += cur * val;
    }
    cout << ans << "\n";
}
