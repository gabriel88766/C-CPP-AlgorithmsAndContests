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
    SegmentTree(){}
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(2*n);
        build(v);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(2*n);
        build();
    }
    void build(){
        for(int i=n;i<2*n;i++) st[i] = nullel();
        for(int i=n-1;i>=1;i--) st[i] = op(st[2*i], st[2*i+1]);
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

pair<int,int> op(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first) return {a.first, min(b.first, a.second)};
    else return {b.first, min(a.first, b.second)};
}

pair<int,int> el(){
    return {INF_INT, INF_INT};
}

SegmentTree<pair<int,int>, op, el> st[9];
void replace(int i, int val){
    int aux = val;
    for(int j=0;j<9;j++){
        int md = aux % 10;
        if(md != 0) st[j].update(i, {val, INF_INT});
        else st[j].update(i, el());
        aux /= 10;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<9;i++) st[i] = SegmentTree<pair<int,int>, op, el>(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        replace(i, x);
    }
    for(int i=1;i<=m;i++){
        int x, l, r;
        cin >> x >> l >> r;
        if(x == 1){
            replace(l, r);
        }else{
            ll bst = INF_LL;
            for(int j=0;j<9;j++){
                auto [a, b] = st[j].query(l, r);
                if(a != INF_INT && b != INF_INT){
                    bst = min(bst, (ll)(a+b));
                }
                // bst = min(bst, a+b);
            }
            if(bst == INF_LL) cout << "-1\n";
            else cout << bst << "\n";
        }
    }
}
