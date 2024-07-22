//almost TLE - seg tree or ordered set or bintrie(Van Emde Boas tree?)
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
        if(l == r) {st[p] = value; return;}
        update(i, value, l, (l + r)/2, 2 * p);
        update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); //some operation
    }
    void update(int i, T value){
        update(i, value, 0, n-1, 1);
    }
    int find(int l, int r, int p, int ord){
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

const int N = 10000000;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    string t;
    cin >> n >> q >> t;
    vector<int> v(n, 0);
    for(int i=0;i<n;i++){
        if(t[i] == '1') v[i] = 1;
    }
    SegmentTree<int, op, el> st(v);
    while(q--){
        int c, k;
        cin >> c >> k;
        if(c == 0){
            st.update(k, 1);
        }else if(c == 1){
            st.update(k, 0);
        }else if(c == 2){
            if(st.query(k, k)) cout << "1\n";
            else cout << "0\n";
        }else if(c == 3){  
            if(st.query(k, n-1) != 0) cout << st.find(st.query(0, k-1)+1) << "\n";
            else cout << "-1\n";
        }else{
            if(st.query(0, k) != 0) cout << st.find(st.query(0, k)) << "\n";
            else cout << "-1\n";
        }
    }
}
