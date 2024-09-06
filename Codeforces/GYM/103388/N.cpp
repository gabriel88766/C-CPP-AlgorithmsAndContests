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
    return 0LL;
}

struct Query{
    int l, r, val, j;
    bool operator< (const Query &q) const{
        return val < q.val;
    }
};
const int N = 3e5+1;
const int M = 1e5+1;
vector<int> ind[M];
int ans[N], v[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int y, n;
    cin >> y >> n;
    for(int i=1;i<=y;i++){
        cin >> v[i];
        ind[v[i]].push_back(i);
    }
    vector<Query> vq;
    for(int i=0;i<n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        int l = x+1;
        int r = x+z;
        int mn = y; //values greater than mn between l and r
        if(r < l) continue;
        if(mn <= v[x]) continue;
        Query q = {l, r, mn, i};
        vq.push_back(q);
    }
    sort(vq.begin(), vq.end());
    SegmentTree<int, op, el> st(y+1);
    for(int i=1;i<=y;i++) st.update(i, 1);
    int xx = 0;
    for(int i=0;i<vq.size();i++){
        auto [l, r, val, j] = vq[i];
        while(xx < val){
            for(auto ids : ind[xx]) st.update(ids, 0);
            xx++;
        }   
        if(r >= l) ans[j] = st.query(l, r);
    }
    for(int i=0;i<n;i++) cout << ans[i] << "\n";
}
