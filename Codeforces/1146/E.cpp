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
                lz[2 * p] = composition(lz[p], lz[2*p]); // += increment = update
                lz[2 * p + 1] = composition(lz[p], lz[2*p + 1]);
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
    return a + b;
}

int el(){
    return 0;
}

int id(){
    return -1;
}

int composition(int a, int b){
    assert(a != id());
    if(b == id()) return a;
    if(a == 0 || a == 1) return a;
    //a == 2
    assert(a == 2);
    if(b == 0 || b == 1) return b^1;
    else return -1; //2 2
}

int apply(int stv, int lzv, int len){
    if(lzv == 2) return stv ^ 1;
    else return lzv;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    const int mid = 100'005;
    const int sz = 200'010;
    SegmentTreeLazy<int, int, op, el, id, composition, apply> st(sz);
    for(int i=0;i<q;i++){
        char c;
        int num;
        cin >> c >> num;
        if(c == '>'){
            if(num >= 0){
                st.update(0, mid-num-1, 0);
                st.update(mid+num+1, sz-1, 1);
            }else{
                num = abs(num);
                st.update(0, mid-num, 0);
                st.update(mid+num, sz-1, 1);
                st.update(mid-num+1, mid+num-1, 2);
            }
        }else{
            if(num <= 0){
                num = abs(num);
                st.update(mid+num+1, sz-1, 0);
                st.update(0, mid - num - 1, 1);
            }else{
                st.update(mid+num, sz-1, 0);
                st.update(0, mid - num, 1);
                st.update(mid - num + 1, mid + num - 1, 2);
            }
        }
    }
    for(int i=0;i<n;i++){
        int ans = st.query(v[i] + mid, v[i] + mid);
        if(ans == 0) cout << v[i] << " ";
        else cout << -v[i] << " ";
    }
    cout << "\n";
}
