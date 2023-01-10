#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 1e5+6;
ll st[4*N];
ll v[N];
int n;

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = v[l]; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}

ll query(int k, int l = 1, int r = n, int node = 1){ //bin search
    if(l == r) return l;
    if(k < st[2 * node]) return query(k, l, (l+r)/2, 2 * node);
    else return query(k - st[2 * node], (l+r)/2+1, r, 2*node+1 );
}

void update(int pos, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[node] ^= 1;  return;}
    update(pos, l, (l + r)/2, 2 * node);
    update(pos, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; 
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    while(q--){
        int a,b,c;
        cin >> a >> b;
        if(a==1){
            update(b+1);
        }else{
            cout << query(b)-1 << "\n";
        }
    }
}
