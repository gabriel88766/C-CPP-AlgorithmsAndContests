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


struct Node{
    pair<int, char> pr, su, mid;
    int len;
    Node(char c){
        len = 1;
        pr = su = mid = {1, c};
    }
    Node(){
        // pr = su = mid = -INF_LL; //to allow negative maximum
        len = 0;
    }
};
Node op(Node a, Node b){
    Node ans;
    if(a.len == a.pr.first && b.pr.second == a.pr.second){
        ans.pr.second = a.pr.second;
        ans.pr.first = a.len + b.pr.first;
    }else if(a.len == 0){
        ans.pr = b.pr;
    }else{
        ans.pr = a.pr;
    }
    if(b.len == b.su.first && a.su.second == b.su.second){
        ans.su.second = a.su.second;
        ans.su.first = a.su.first + b.len;
    }else if(b.len == 0){
        ans.su = a.su;
    }else{
        ans.su = b.su;
    }
    ans.len = a.len + b.len;
    ans.mid = max(a.mid, b.mid);
    if(a.su.second == b.pr.second && a.su.first + b.pr.first > ans.mid.first){
        ans.mid = {a.su.first + b.pr.first, a.su.second};
    }
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
    string s;
    cin >> n >> q >> s;
    s = " " + s;
    SegmentTree<Node, op, el> st(n+1);
    for(int i=1;i<=n;i++){
        st.update(i, Node(s[i]));
    }
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int j;
            char c;
            cin >> j >> c;
            st.update(j, Node(c));
        }else{
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r).mid.first << "\n";
        }
    }
}
