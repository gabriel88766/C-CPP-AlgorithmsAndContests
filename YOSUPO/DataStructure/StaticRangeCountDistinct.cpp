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
        st.resize(2*n);
        build(v);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(2*n);
    }
    void build(vector<T> &v){
        for(int i=n;i<2*n;i++) st[i] = v[i-n];
        for(int i=n-1;i>=1;i--) st[i] = op(st[2*i], st[2*i+1]); //merge op
    }
    T query(int l, int r){
        T ans = nullel();
        l += n, r += n;
        while(l <= r){
            int no = l, c = 1;
            while(!(no & 1) && (r-l+1) >= (c << 1)){
                c <<= 1;
                no >>= 1;
            }
            ans = op(ans, st[no]); //merge op
            l += c;
        }
        return ans;
    }
    void update(int l, T val){
        l += n;
        st[l] = val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}

struct Query{
    int l, r, i;
    bool operator< (const Query &q) const{
        return l < q.l;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    vector<int> nxt(n+1);
    map<int, int> mp; 
    SegmentTree<int, op, el> st(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(mp.count(v[i])){
            nxt[mp[v[i]]] = i;
        }else{
            st.update(i, 1);
        }
        mp[v[i]] = i;
    }
    vector<Query> vq(q);
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        vq[i].l = a+1;
        vq[i].r = b;
        vq[i].i = i;
    }
    sort(vq.begin(), vq.end());
    int p = 1;
    for(int i=0;i<q;i++){
        while(p < vq[i].l){
            st.update(p, 0);
            if(nxt[p]){
                st.update(nxt[p], 1);
            }
            p++;
        }
        int ansc = st.query(vq[i].l, vq[i].r);
        ans[vq[i].i] = ansc;
    }
    for(int i=0;i<q;i++) cout << ans[i] << "\n";
}
