#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Node{
    ll pr, su, mid, sum;
    Node(ll val){
        pr = su = mid = sum = val;
    }
    Node(){
        pr = su = mid = sum = 0;
    }
};
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

Node op(Node a, Node b){
    Node ans;
    ans.pr = max(a.pr, a.sum + b.pr);
    ans.sum = a.sum + b.sum;
    ans.su = max(b.su, a.su + b.sum);
    ans.mid = max({a.mid, b.mid, a.su + b.pr});
    return ans;
}

Node el(){
    Node null;
    return null;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    SegmentTree<Node, op, el> st(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        st.update(i, Node(x));
    }
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r).mid << "\n";
    }
}
