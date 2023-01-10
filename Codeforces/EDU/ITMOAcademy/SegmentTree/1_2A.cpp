#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+6;
ll lmax[4*N], rmax[4*N], st[4*N], midmax[4*N]; //left and right and mid subarray
ll v[N];
int n;
 
void build(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = rmax[node] = lmax[node] = midmax[node] = v[l]; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    lmax[node] = max(lmax[2 * node], st[2 * node] + lmax[2 * node + 1]); 
    rmax[node] = max(rmax[2 * node + 1], rmax[2 * node] + st[2 * node + 1]);
    st[node] = st[2 * node] + st[2 * node + 1];
    midmax[node] = max(rmax[2 * node] + lmax[2 * node + 1], max(midmax[2 * node], midmax[2 * node + 1]));
}
 
ll query(){
    return midmax[1];
}
 
void update(int pos, ll value, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[node] = rmax[node] = lmax[node] = midmax[node] = value;  return;}
    update(pos, value, l, (l + r)/2, 2 * node);
    update(pos, value, (l + r)/2 + 1, r, 2 * node + 1);
    lmax[node] = max(lmax[2 * node], st[2*node] + lmax[2 * node + 1]); 
    rmax[node] = max(rmax[2 * node + 1], rmax[2 * node] + st[2 * node + 1]);
    st[node] = st[2 * node] + st[2 * node + 1];
    midmax[node] = max(rmax[2 * node] + lmax[2 * node + 1], max(midmax[2 * node], midmax[2 * node + 1]));
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    cout << (query() > 0 ? query() : 0) << "\n";
    while(m--){
        int a,b;
        cin >> a >> b;
        update(a+1, b);
        auto ans = query();
        cout << (ans > 0 ? ans : 0) << "\n";
    }
}
