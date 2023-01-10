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
    if(l == r){ st[node] = v[l]; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    st[node] = max(st[2 * node], st[2 * node + 1]); //some operation
}

void push(int l, int r, int node){
    if(lz[node]){
        st[node] += lz[node]; //if RSQ (r-l+1) * lz |=> = if update, += if increment
        if(l != r){
            lz[2 * node] += lz[node]; // = if update, += if increment
            lz[2 * node + 1] += lz[node];
        } 
        lz[node] = 0;
    }
}

ll query(int i, int j, int l = 1, int r = n, int node = 1){
    push(l, r, node);
    if(j < l || i > r) return -INF_LL; //identity element
    if(j >= r && i <= l) return st[node];
    return max(query(i, j, l, (l + r)/2, 2 * node), query(i, j, (l + r)/2 + 1, r, 2 * node + 1)); //some operation
}

void update(int i, int j, ll value, int l = 1, int r = n, int node = 1){
    push(l, r, node);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[node] = value; push(l, r, node); return;}
    update(i, j, value, l, (l + r)/2, 2 * node);
    update(i, j, value, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = max(st[2 * node], st[2 * node + 1]); //some operation
}

ll u[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    int q;
   
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> u[i];
    for(int i=1;i<=n;i++) v[i] = u[i] + v[i-1];
    build();
    for(int i=0; i < q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            ll old = u[b];
            u[b] = c;
            ll dif = c - old;
            update(b, n, dif);
        }else{ 
            ll ans;
            if(b != 1) ans = query(b, c) - query(b-1, b-1);
            else ans = query(b, c);
            if(ans > 0) cout << ans << "\n";
            else cout << "0\n";
        }
    }
}
