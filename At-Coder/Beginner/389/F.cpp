#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, 0);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p] += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, T val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T val){
        update(i, j, val, 0, n-1, 1);
    }
    int findFirst(int l, int r, int p, int val){
        if(l == r) return l;
        int m = (l + r)/2;
        push(l, m, 2*p);
        if(st[2*p] >= val) return findFirst(l, m, 2*p, val);
        else{
            push(m+1, r, 2*p+1);
            return findFirst(m+1, r, 2*p+1, val);
        }
    }
    int findFirst(int val){//segtree maximum
        push(0, n-1, 1);
        return findFirst(0, n-1, 1, val);
    }
    int findLast(int l, int r, int p, int val){
        if(l == r) return l;
        int m = (l + r)/2;
        push(m+1, r, 2*p+1);
        if(st[2*p+1] <= val) return findLast(m+1, r, 2*p+1, val);
        else{
            push(l, m, 2*p);
            return findLast(l, m, 2*p, val);
        }
    }
    int findLast(int val){//segtree minimum
        push(0, n-1, 1);
        return findLast(0, n-1, 1, val);
    }
};

int opmx(int a, int b){
    return max(a, b);
}

int elmx(){
    return 0;
}

int opmn(int a, int b){
    return min(a, b);
}

int elmn(){
    return INF_INT;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<int> ini(500001, 0);
    for(int i=1;i<=500000;i++) ini[i] = i;
    int n;
    cin >> n;
    SegmentTreeLazy<int, opmn, elmn> stmn(ini);
    SegmentTreeLazy<int, opmx, elmx> stmx(ini);
    for(int i=1;i<=n;i++){
        int l, r;
        cin >> l >> r;
        int rl = stmx.findFirst(l);
        int rr = stmn.findLast(r);
        stmn.update(rl, rr, 1);
        stmx.update(rl, rr, 1);
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        cout << stmn.query(x, x)  << "\n";
    }
}
