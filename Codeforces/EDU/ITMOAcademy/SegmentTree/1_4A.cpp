#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;
 
const int N = 2e5+6;
ll st[4*N], lz[4*N];
ll v[N];
int n;
 
void build(int l = 1, int r = n, int node = 1){
    if(l == r){ if(l % 2) st[node] = -v[l]; else st[node] = v[l]; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}
 
ll query(int i, int j, int l = 1, int r = n, int node = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[node];
    return query(i, j, l, (l + r)/2, 2 * node) + query(i, j, (l + r)/2 + 1, r, 2 * node + 1); //some operation
}
 
void update(int pos, ll value, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {if(l % 2) st[node] = -value; else st[node] = value;   return;}
    update(pos, value, l, (l + r)/2, 2 * node);
    update(pos, value, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    cin >> q;
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 0){
            update(b, c);
        }else{
            if(b%2) cout << -query(b, c) << "\n";
            else cout << query(b, c) << "\n";
        }
    }
}