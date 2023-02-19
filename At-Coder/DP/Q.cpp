#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll dp[N];

ll st[4*N];
int n;

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return max(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); //some operation
}

void update(int pos, ll value, int l = 1, int r = n, int p = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[p] = value;  return;}
    update(pos, value, l, (l + r)/2, 2 * p);
    update(pos, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = max(st[2 * p], st[2 * p + 1]); //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll ans = 0, cur = 0;
    cin >> n;
    vector<ll> h(n), a(n);
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        cur = query(1, h[i]);
        cur += a[i];
        update(h[i], cur);
        ans = max(ans, cur);
    }
    cout << ans;
}
