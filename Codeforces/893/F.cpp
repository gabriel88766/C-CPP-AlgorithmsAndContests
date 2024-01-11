#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//Segment tree persistent ??????
template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    vector<int> lc, rc;
    int n, cnt, rt;
    SegmentTree(ll sz){ //queries * 40
        n = sz;
        st.resize(40*n);
        lc.resize(40*n);
        rc.resize(40*n);
        rt = build(1, n);
    }
    int build(int l, int r){
        int p = ++cnt;
        if(l == r){ st[p] = nullel(); return p; }
        lc[p] = build(l, (l+r)/2);
        rc[p] = build((l+r)/2 + 1, r);
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
    return min(a, b);
}

int el(){
    return INF_INT;
}

const int M = 1e5+1;
vector<int> adj[M];
int h[M], sub[M], ord[M], invord[M], tah[M];
int mh = 0;
int cnt2 = 0;

void dfs(int u, int p){
    ord[u] = ++cnt2;
    invord[cnt2] = u;
    h[u] = h[p] + 1;
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, r;
    cin >> n >> r;
    h[0] = -1;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(r, 0);
    for(int i=1;i<=n;i++) mh = max(mh, h[i]);
    vector<pair<int,int>> vp;
    for(int i=1;i<=n;i++){
        vp.push_back({h[i], i});
    }
    sort(vp.begin(), vp.end());
    int p = 0;
    SegmentTree<int, op, el> st(n);
    int curt = st.rt;
    for(int i=0;i<=mh;i++){
        while(p < vp.size() && vp[p].first == i){
            curt = st.update(ord[vp[p].second], v[vp[p].second], curt);
            p++;
        }
        tah[i] = curt;
    }
    int q;
    cin >> q;
    int last = 0;
    for(int i=0;i<q;i++){
        int x, k;
        cin >> x >> k;
        x = (x + last) % n + 1;
        k = (k + last) % n;
        k += h[x];
        last = st.query(ord[x], ord[x] + sub[x] - 1, tah[min(k, mh)]);
        cout << last << "\n";
    }
}
