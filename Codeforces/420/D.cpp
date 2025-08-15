#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    int n;
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        build(v, 0, n-1, 1);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(4*n);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){st[p] = v[l]; return;}
        build(v, l, (l+r)/2, 2*p);
        build(v, (l+r)/2+1, r, 2*p+1);
        st[p] = op(st[2*p], st[2*p+1]);
    }
    T query(int i, int j, int l, int r, int p){
        if(j < l || i > r) return nullel(); 
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, T value, int l, int r, int p){
        if(i < l || i > r) return;
        if(l == r) {st[p] = value; return;}
        update(i, value, l, (l + r)/2, 2 * p);
        update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); //some operation
    }
    void update(int i, T value){
        update(i, value, 0, n-1, 1);
    }
    int find(int l, int r, int p, int ord){ //segtree op must be sum.
        if(l == r) return l;
        int m = (l + r)/2;
        if(st[2*p] >= ord) return find(l, m, 2*p, ord);
        else return find(m+1, r, 2*p+1, ord-st[2*p]);
    }
    int find(int ord){
        return find(0, n-1, 1, ord);
    }
};

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}


const int N = 2e6+3;
int val[N];
int p[N];
int ans[N];
bool used[N], vis[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> vx(n+m+1);
    for(int i=m+1;i<=n+m;i++) vx[i] = 1;
    SegmentTree<int, op, el> st(vx);
    bool ok = true;
    for(int i=1;i<=m;i++){
        int x, y;
        cin >> x >> y;
        int ord = st.find(y);
        if(val[ord] == x || (val[ord] == 0 && used[x] == false)){
            used[x] = true;
            val[m+1-i] = x;
            p[m+1-i] = ord;
            st.update(ord, 0);
            st.update(m+1-i, 1);
        }else {
            ok = false;
        }
    }
    if(!ok){
        cout << "-1\n";
        return 0;
    }
    for(int i=1;i<=m;i++){
        if(st.query(i, i) == 1 && vis[i] == false){
            int px = i;
            while(px <= m){
                vis[px] = true;
                px = p[px];
            }
            ans[px - m] = val[i];
        }
    }
    int rp = 1;
    for(int i=1;i<=n;i++){
        while(used[rp]) rp++;
        if(ans[i] == 0){
            ans[i] = rp++;
        }
        cout << ans[i] << " ";
    }
    cout << "\n";
}
