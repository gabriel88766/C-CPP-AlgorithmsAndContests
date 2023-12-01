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
};

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        SegmentTree<int, op, el> st(v);
        set<int> s;
        for(int i=0;i<n;i++){
            if(v[i] == 1) s.insert(i);
        }
        for(int i=0;i<q;i++){
            int ty;
            cin >> ty;
            if(ty == 1){    
                int sum;
                cin >> sum;
                if(s.size()){
                    int beg = *s.begin();
                    int en = *prev(s.end());
                    int sum1 = st.query(beg, n-1);
                    int sum2 = st.query(0, en);
                    int ts = st.query(0, n-1);
                    if(max(sum1, sum2) >= sum) cout << "YES\n";
                    else if(ts >= sum && sum % 2 == ts % 2) cout << "YES\n";
                    else cout << "NO\n";
                }else{
                    int ts = st.query(0, n-1);
                    if(ts >= sum && ts%2 == sum % 2) cout << "YES\n";
                    else cout << "NO\n";
                }
            }else{
                int ind, num;
                cin >> ind >> num;
                --ind;
                if(v[ind] == 1) s.erase(ind);
                v[ind] = num;
                if(v[ind] == 1) s.insert(ind);
                st.update(ind, num);
            }
        }

    }
}
