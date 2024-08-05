#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 1e5+6;
ll st[4*N], st2[4*N];
ll v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = st2[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
    st2[p] = max(st2[2*p], st2[2*p+1]);
}

ll query_sum(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query_sum(i, j, l, (l + r)/2, 2 * p) + query_sum(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update_point(int i, ll value, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[p] = value; st2[p] = value; return;}
    update_point(i, value, l, (l + r)/2, 2 * p);
    update_point(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
    st2[p] = max(st2[2*p], st2[2*p+1]);
}

void update_range(int i, int j, ll value, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return;
    if(l == r){
        ll x = st[p] % value;
        st2[p] = st[p] = x;
        return;
    }
    int mid = (l + r)/2;
    if(st2[2*p] >= value) update_range(i, j, value, l, mid, 2*p);
    if(st2[2*p+1] >= value) update_range(i, j, value, mid+1, r, 2*p+1);
    st[p] = st[2 * p] + st[2 * p + 1]; 
    st2[p] = max(st2[2*p], st2[2*p+1]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    int q;
    cin >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    for(int i=1;i<=q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int l, r;
            cin >> l >> r;
            cout << query_sum(l, r) << "\n";
        }else if(t == 2){
            int l, r, x;
            cin >> l >> r >> x;
            update_range(l, r, x);
        }else{
            int l, x;
            cin >> l >> x;
            update_point(l, x);
        }
    }
}
