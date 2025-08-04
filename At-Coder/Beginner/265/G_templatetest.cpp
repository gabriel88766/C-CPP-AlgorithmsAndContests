//THIS IS G, but with segment tree template
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, typename S, T (*op)(T, T), T (*el)(), S (*id)(),\
 S (*composition)(S, S), T (*apply)(T, S, int)>
struct SegmentTreeLazy{
    vector<T> st;
    vector<S> lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, id());
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, el());
        lz.assign(4*n, id());
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != id()){ //0 can be assigned? change!
            st[p] = apply(st[p], lz[p], r-l+1);
            if(l != r){
                lz[2 * p] = composition(lz[2*p], lz[p]); // += increment = update
                lz[2 * p + 1] = composition(lz[2*p + 1], lz[p]);
            } 
            lz[p] = id();
        }
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return el();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, S val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, S val){
        update(i, j, val, 0, n-1, 1);
    }
};

struct Node{
    array<ll, 3> cnt;
    array<array<ll, 3>, 3> inv; //00 11 and 22 are meaningless
    Node(){
        for(int j=0;j<=2;j++){
            cnt[j] = 0;
            for(int i=0;i<=2;i++){
                inv[i][j] = 0;
            }
        }
    }
    Node(int x) : Node() {
        cnt[x] = 1;
    }
};

Node op(Node a, Node b){
    Node ans;
    for(int i=0;i<=2;i++){
        ans.cnt[i] = a.cnt[i] + b.cnt[i];
        for(int j=0;j<=2;j++){
            ans.inv[i][j] = a.inv[i][j] + b.inv[i][j] + a.cnt[i] * b.cnt[j];
        }
    }
    return ans;
}

Node el(){
    Node null;
    return null;
}

array<int, 3> id(){
    return {0, 1, 2};
}

array<int, 3> composition(array<int, 3> lef, array<int, 3> rig){
    array<int, 3> ans;
    for(int i=0;i<=2;i++){
        ans[i] = rig[lef[i]];
    }
    return ans;
}

Node apply(Node stv, array<int, 3> lzv, int len){
    Node ans;
    for(int i=0;i<=2;i++){
        ans.cnt[lzv[i]] += stv.cnt[i];
        for(int j=0;j<=2;j++){
            ans.inv[lzv[i]][lzv[j]] += stv.inv[i][j];
        }
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<Node> vx(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        vx[i] = Node(x);
    }
    SegmentTreeLazy<Node, array<int, 3>, op, el, id, composition, apply> st(vx);
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int l, r;
            cin >> l >> r;
            auto nd = st.query(l, r);
            cout << nd.inv[2][1] + nd.inv[2][0] + nd.inv[1][0] << "\n";
        }else{
            int l, r, s, t, u;
            cin >> l >> r >> s >> t >> u;
            array<int, 3> upd = {s, t, u};
            st.update(l, r, upd);
        }
    }
}
