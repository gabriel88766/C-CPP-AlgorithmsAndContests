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
    SegmentTree(ll sz){ //queries * 40
        n = sz;
        st.resize(40*n);
        lc.resize(40*n);
        rc.resize(40*n);
        cnt = 0;
        rt = build(1, n);
    }
    int build(int l, int r){
        int p = ++cnt;
        if(l == r){ st[p] = nullel(); return p; }
        lc[p] = build(l, (l+r)/2);
        rc[p] = build((l+r)/2 + 1, r);
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
    return a+b;
}

ll el(){
    return 0LL;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
         cin >> v[i].first;
         v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    v.push_back({INF_INT, n+1});
    vector<int> curst;
    SegmentTree<ll, op, el> st(600000);
    curst.push_back(st.rt);
    for(int i=0;i<n;i++){
        curst.push_back(st.update(v[i].second, v[i].first, curst.back()));
    }   
    cin >> q;
    ll lans = 0;
    for(int i=0;i<q;i++){
        ll l, r, x;
        cin >> l >> r >> x;
        l = l ^ lans;
        r = r ^ lans;
        x = x ^ lans;
        int ind = 0;
        for(int j=n/2;j>=1;j>>=1){
            while(ind + j <= n && v[ind+j].first <= x) ind += j;
        }
        if(v[ind].first <= x) ind++;
        lans = st.query(l, r, curst[ind]);
        cout << lans << "\n";
    }
}
