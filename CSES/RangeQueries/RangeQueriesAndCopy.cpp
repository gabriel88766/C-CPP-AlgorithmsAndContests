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
    vector<int> lc, rc;
    int n, cnt, rt;
    SegmentTree(vector<T> &v, ll sz){ //queries * 40
        n = v.size() - 1;
        st.resize(40*sz);
        lc.resize(40*sz);
        rc.resize(40*sz);
        cnt = 0;
        rt = build(v, 1, n);
    }
    int build(vector<T> &v, int l, int r){
        int p = ++cnt;
        if(l == r){st[p] = v[l]; return p; }
        lc[p] = build(v, l, (l+r)/2);
        rc[p] = build(v, (l+r)/2 + 1, r);
        st[p] = op(st[lc[p]], st[rc[p]]); //some operation
        return p;
    }
    T query(int i, int j, int p, int l, int r){
        if(j < l || i > r) return nullel(); //identity element
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, lc[p], l, (l + r)/2), query(i, j, rc[p], (l + r)/2 + 1, r)); //some operation
    }

    T query(int i, int j, int p){
        return query(i, j, p, 1, n);
    }
    
    int update(int i, int value, int olp, int l, int r){
        if(i < l || i > r) return olp;
        int p = ++cnt;
        if(l == r) {st[p] = value; return p;}
        lc[p] = update(i, value, lc[olp], l, (l + r)/2);
        rc[p] = update(i, value, rc[olp], (l + r)/2 + 1, r);
        st[p] = op(st[lc[p]], st[rc[p]]);
        return p;
    }
    int update(int i, int value, int olp){
        return update(i, value, olp, 1, n);
    }
};

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    SegmentTree<ll, op, el> st(v, n+q);
    vector<int> arr;
    arr.push_back(st.rt);
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int x, pos, v;
            cin >> x >> pos >> v;
            arr[x-1] = st.update(pos, v, arr[x-1]);
        }else if(t == 2){
            int x, a, b;
            cin >> x >> a >> b;
            cout << st.query(a, b, arr[x-1]) << "\n";
        }else{
            int x;
            cin >> x;
            arr.push_back(arr[x-1]);
        }
    }
}
