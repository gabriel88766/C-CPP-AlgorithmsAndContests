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
        if(lz[p]){ //0 can be assigned? change!
            st[p] = (r - l + 1) - st[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] ^= lz[p]; // += increment = update
                lz[2 * p + 1] ^= lz[p];
            } 
            lz[p] = 0;
        }
    }

    ll query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    ll query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] ^= 1; push(l, r, p); return;}
        update(i, j, l, (l + r)/2, 2 * p);
        update(i, j, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j){
        update(i, j, 0, n-1, 1);
    }
};

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<SegmentTreeLazy<int, op, el>> st(20, SegmentTreeLazy<int,op,el>(n+1));
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        for(int j=0;j<20;j++){
            if(x & (1 << j)){
                st[j].update(i, i);
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r, x;
        int t;
        cin >> t;
        if(t == 1){
            cin >> l >> r;
            ll ans = 0;
            for(int j=0;j<20;j++){
                ans += (1LL << j) * st[j].query(l, r);
            }
            cout << ans << "\n";
        }else{
            cin >> l >> r >> x;
            for(int j=0;j<20;j++){
                if(x & (1 << j)){
                    st[j].update(l, r);
                }
            }
        }
    }
}
