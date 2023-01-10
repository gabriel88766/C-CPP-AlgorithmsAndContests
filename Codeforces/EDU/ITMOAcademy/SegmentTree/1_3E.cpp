#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+6;
ll st[4*N], lz[4*N];
ll v[N];
int n;

ll query(int i, int j, int l = 1, int r = n, int node = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[node];
    return query(i, j, l, (l + r)/2, 2 * node) + query(i, j, (l + r)/2 + 1, r, 2 * node + 1); //some operation
}

void update(int pos, ll value, int l = 1, int r = n, int node = 1){
    if(pos < l || pos > r) return;
    if(l == r) {st[node] += value;  return;}
    update(pos, value, l, (l + r)/2, 2 * node);
    update(pos, value, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q, t;
    cin >> n >> q;
    while(q--){
        int a,b,c;
        cin >> a;
        if(a==1){
            cin >> a >> b >> c;
            update(a+1, c);
            if(b < n) update(b+1, -c);
        }else{
            cin >> a;
            cout << query(0, a+1) << "\n";
        }
    }
}
