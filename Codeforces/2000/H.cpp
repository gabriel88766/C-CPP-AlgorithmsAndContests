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
    int find(int l, int r, int p, int ord){ //segtree op must be sum.
        if(l == r) return l;
        int m = (l + r)/2;
        if(st[2*p] >= ord) return find(l, m, 2*p, ord);
        else return find(m+1, r, 2*p+1, ord);
    }
    int find(int ord){
        return find(0, n-1, 1, ord);
    }
};

int op(int a, int b){
    return max(a, b);
}

int el(){
    return 0;
}

const int N = 2e6+5;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    SegmentTree<int, op, el> st(N);
    int t;
    cin >> t;
    while(t--){
        vector<int> chg;
        int n, m;
        cin >> n;
        set<int> s;
        s.insert(0);
        s.insert(INF_INT);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            s.insert(x);
        }
        for(auto it = next(s.begin()); it != s.end(); ++it){
            auto pr = *prev(it);
            auto cur = *it;
            st.update(pr+1, cur - pr - 1);
            chg.push_back(pr+1);
        }
        cin >> m;
        for(int i=0;i<m;i++){
            char x;
            int p;
            cin >> x >> p;
            if(x == '-'){
                auto it = s.lower_bound(p);
                int pr = *prev(it);
                int cur = *it;
                int nx = *next(it);
                st.update(cur+1, 0);
                st.update(pr+1, nx - pr - 1);
                s.erase(p);
            }else if(x == '+'){
                s.insert(p);
                auto it = s.lower_bound(p);
                int pr = *prev(it);
                int cur = *it;
                int nx = *next(it);
                st.update(pr+1, cur - pr - 1);
                st.update(cur+1, nx - cur - 1);
                chg.push_back(cur + 1);
            }else{
                cout << st.find(p) << " ";
            }
        }
        cout << "\n";



        for(auto x : chg) st.update(x, 0);
    }
}
