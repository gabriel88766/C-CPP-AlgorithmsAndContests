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
    void update(int l, int val){
        l += n;
        st[l].su += val; //assign or increment?
        st[l].sum += val;
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};



struct Node{
    int su, sum;
    Node(int val){
        su = sum = val;
    }
    Node(){ //to allow negative maximum
        su = sum = 0;
    }
};
Node op(Node a, Node b){
    Node ans;
    ans.sum = a.sum + b.sum;
    ans.su = max(b.su, a.su + b.sum);
    return ans;
}

Node el(){
    Node null;
    null.su = -INF_INT;
    return null;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, m;
    cin >> n >> k >> m;
    SegmentTree<Node, op, el> st(2*n + m + 1);
    for(int i=1;i<=2*n+m;i++) st.update(i, -1);
    set<pair<int, int>> usd;
    multiset<int> msx;
    for(int i=1;i<=m;i++){
        int x, y;
        cin >> x >> y;
        int mn = y + abs(k - x);
        if(usd.count({x, y})){
            st.update(mn, -1);
            usd.erase({x, y});
            msx.erase(msx.find(mn));
        }else{
            st.update(mn, 1);
            usd.insert({x, y});
            msx.insert(mn);
        }
        int lo = n;
        if(msx.size()){
            lo = max(lo, *prev(msx.end()));
            lo += max(st.query(1, lo).su, 0);
        } 
        
        cout << lo-n << "\n";
    }
}
