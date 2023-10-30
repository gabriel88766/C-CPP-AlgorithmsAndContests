#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
ll st[4*N], lz[4*N];
int st2[4*N];
ll v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st2[p] = st[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
    st2[p] = min(st2[2*p], st2[2*p+1]);
}

void push(int l, int r, int p){
    if(lz[p]){ //0 can be assigned? change!
        st[p] = (ll)(r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        st2[p] = lz[p]; 
        if(l != r){
            lz[2 * p] = lz[p]; // += increment = update
            lz[2 * p + 1] = lz[p];
        } 
        lz[p] = 0;
    }
}

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

int query2(int i, int j, int y, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return INF_INT; //identity element;
    if(l == r){
        if(st2[p] <= y) return l;
        else return INF_INT;
    }
    if(st2[2*p] <= y){
        int ans = query2(i, j, y, l, (l + r)/2, 2 * p);
        if(ans != INF_INT) return ans;
        else return query2(i, j, y, (l + r)/2 + 1, r, 2 * p + 1);
    }else if(st2[2*p+1] <= y){
        return query2(i, j, y, (l + r)/2 + 1, r, 2 * p + 1);
        
    }else return INF_INT;
}

void update(int i, int j, ll value, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = value; push(l, r, p); return;}
    update(i, j, value, l, (l + r)/2, 2 * p);
    update(i, j, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
    st2[p] = min(st2[2*p], st2[2*p+1]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    for(int i=0;i<q;i++){
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            int k = query2(1, x, y);
            if(k <= x) update(k, x, y);
        }else{
            int ans = 0, cur = x;
            while(y > 0){
                int k = query2(cur, n, y);
                if(k != INF_INT){
                    ll val = query(k, k);
                    ll tt = min(y/val, (ll)(n-k+1));
                    ans += tt;
                    y -= query(k, k+tt-1);
                    cur = k + tt;
                    if(k+tt-1 == n) break;
                }else break;
            }
            cout << ans << "\n";
        }
    }
}
