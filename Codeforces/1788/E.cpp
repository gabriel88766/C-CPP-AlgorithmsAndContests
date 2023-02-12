#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int dp[N], st[4*N];
int n;

ll query(int i, int j, int l = 1, int r = n, int node = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[node];
    return max(query(i, j, l, (l + r)/2, 2 * node), query(i, j, (l + r)/2 + 1, r, 2 * node + 1)); 
}

void update(int pos, int value, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[node] = value;  return;}
    update(pos, value, l, (l + r)/2, 2 * node);
    update(pos, value, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = max(st[2 * node], st[2 * node + 1]); //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> n;
    vector<ll> v(n+1), ps(n+1), lo(n+1, -1);
    ps[0] = 0;
    set<pair<ll,ll>> nps;
    nps.insert({0, 0});
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
        nps.insert({ps[i], i});
    }
    ll lower = INF_LL;
    for(int i=0;i<=n;i++){
        if(ps[i] < lower){
            auto it = nps.upper_bound({ps[i], i});
            while(it != nps.end() && it->first < lower){
                lo[it->second] = i;
                ++it;
            }
            lower = ps[i];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int l = lo[i];
        if(l == -1) continue;
        dp[i] = i-l;
        if(l > 1) dp[i] += query(1, l-1);
        update(i, dp[i]);
    }
    for(int i=1;i<=n;i++) cout << dp[i] << " ";

}
 