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
        if(l == r) {st[p] += value; return;}
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


const int N = 2e5+6;
 
ll bit[N];
 
ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}
 
void add(int b, ll value){ //add value to position b
    for(int i = b; i <= N; i += i & -i){
        bit[i] += value;
    }
}
 

int cp = 0;
SegmentTree<int, op, el> stf(200005);

ll ans[200005];
vector<pair<ll, ll>> vs;
vector<int> ord;
vector<int> inv;
void dcdp(int l, int r, int opl, int opr){
    ll bst = -INF_LL;
    int opm = -1;
    int m = (l + r)/2;
    for(int i=opl;i<=opr;i++){
        while(cp < i){
            cp++;
            stf.update(inv[cp], 1);
            add(inv[cp], vs[cp].second);
        }
        while(cp > i){
            stf.update(inv[cp], -1);
            add(inv[cp], -vs[cp].second);
            cp--;
        }
        if(i >= m){
            int id = stf.find(m);
            ll sum = query(id);
            if(sum - vs[i].first > bst){
                bst = sum - vs[i].first;
                opm = i;
            }
        }
    }
    ans[m] = bst;
    if(l != r){
        if(l != m) dcdp(l, m-1, opl, opm);
        dcdp(m+1, r, opm, opr);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vs.resize(n+1);
    vs[0] = {-INF_LL, INF_LL};
    for(int i=1;i<=n;i++){
        cin >> vs[i].second >> vs[i].first;
    }
    sort(vs.begin(), vs.end());
    ord.resize(n+1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){
        return vs[a].second > vs[b].second;
    });
    inv.resize(n+1);
    for(int i=0;i<=n;i++){
        inv[ord[i]] = i;
    }
    dcdp(1, n, 1, n);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
}
