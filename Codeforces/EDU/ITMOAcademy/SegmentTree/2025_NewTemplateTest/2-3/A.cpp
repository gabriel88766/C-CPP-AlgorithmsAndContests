#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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
    ll pr, su, mid, sum;
    Node(ll val){
        pr = su = mid = sum = val;
    }
    Node(){
        pr = su = mid = 0; 
        sum = 0;
    }
};

Node op(Node a, Node b){
    Node ans;
    ans.pr = max(a.pr, a.sum + b.pr);
    ans.sum = a.sum + b.sum;
    ans.su = max(b.su, a.su + b.sum);
    ans.mid = max({a.mid, b.mid, a.su + b.pr});
    return ans;
}

Node el(){
    Node null;
    return null;
}

ll id(){
    return INF_LL; //impossible element
}

ll composition(ll a, ll b){
    return b;
}

Node apply(Node stv, ll lzv, int len){
    Node nde;
    if(lzv >= 0){
        nde.pr = nde.mid = nde.su = lzv * len;
    }
    nde.sum = lzv * len;
    return nde;
}

//declare as SegmentTreeLazy<ll, ll, op, el, id, composition, apply> st(ini);

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<Node> ini(n, Node(0));
    SegmentTreeLazy<Node, ll, op, el, id, composition, apply> st(ini);
    for(int i=0;i<m;i++){
        int tq;
        int l, r, v;
        cin >> l >> r >> v;
        st.update(l, r-1, v);
        cout << st.st[1].mid << "\n";
    }
}
