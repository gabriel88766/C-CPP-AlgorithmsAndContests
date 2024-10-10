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
    vector<int> lc, rc;
    int n, cnt, rt;
    SegmentTree(ll sz, vector<int> &ini){ //queries * 40
        n = sz;
        st.resize(80*n);
        lc.resize(80*n);
        rc.resize(80*n);
        cnt = 0;
        rt = build(1, n, ini);
    }
    int build(int l, int r, vector<int> &ini){
        int p = ++cnt;
        if(l == r){ st[p] = ini[l]; return p; }
        lc[p] = build(l, (l+r)/2, ini);
        rc[p] = build((l+r)/2 + 1, r, ini);
        st[p] = op(st[lc[p]], st[rc[p]]); //some operation
        return p;
    }
    T query(int i, int j, int p, int l, int r){
        if(j < l || i > r) return nullel(); //identity element
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, lc[p], l, (l + r)/2), query(i, j, rc[p], (l + r)/2 + 1, r)); //some operation
    }

    T query(int i, int j, int p){
        return query(i, j, p, 1, n);
    }
    
    int update(int i, int value, int olp, int l, int r){
        if(i < l || i > r) return olp;
        int p = ++cnt;
        if(l == r) {st[p] = value; return p;}
        lc[p] = update(i, value, lc[olp], l, (l + r)/2);
        rc[p] = update(i, value, rc[olp], (l + r)/2 + 1, r);
        st[p] = op(st[lc[p]], st[rc[p]]);
        return p;
    }
    int update(int i, int value, int olp){
        return update(i, value, olp, 1, n);
    }
};

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}
const int N = 1e5+3;
vector<int> pos[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1), a(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a[i] = x;
        pos[x].push_back(i);
    }
    for(int i=1;i<=100000;i++){
        if(pos[i].size()){
            for(int j=0;j<min((int)pos[i].size(), k); j++){
                v[pos[i][j]] = 1;
            }
        }
    }
    SegmentTree<int, op, el> st(n, v);
    vector<int> rts(n+1);
    rts[1] = st.rt;
    for(int i=2;i<=n;i++){
        int val = a[i-1];
        int ind = lower_bound(pos[val].begin(), pos[val].end(), i-1) - pos[val].begin();
        if(ind + k < pos[val].size()){
            rts[i] = st.update(pos[val][ind + k], 1, rts[i-1]);
        }else rts[i] = rts[i-1];
    }
    int q;
    cin >> q;
    int last = 0;
    while(q--){
        int l, r;
        cin >> l >> r;
        l = ((last + l) % n) + 1;
        r = ((last + r) % n) + 1;
        if(l > r) swap(l, r);
        last = st.query(l, r, rts[l]);
        cout << last << "\n";
    }

}
