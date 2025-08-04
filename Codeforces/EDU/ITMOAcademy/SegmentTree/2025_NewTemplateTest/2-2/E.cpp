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

int op(int a, int b){
    return min(a, b);
}

int el(){
    return INF_INT;
}

int id(){
    return -1; //assign 0 must be allowed
}

int composition(int a, int b){
    return b;
}

int apply(int stv, int lzv, int len){
    return lzv;
}

//declare as SegmentTreeLazy<ll, ll, op, el, push_sum, id> st(n+1);

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> ini(n, 0);
    SegmentTreeLazy<int, int, op, el, id, composition, apply> st(ini);
    for(int i=0;i<m;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int l, r, v;
            cin >> l >> r >> v;
            st.update(l, r-1, v);
        }else{
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r-1) << "\n";
        }
    }
}
