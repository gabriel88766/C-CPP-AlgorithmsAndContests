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
        st[l] += val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}


//query value (1, i)
//update range(l, r) (l, v) ; (r+1, -v)
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    ll csum = 0;
    SegmentTree<ll, op, el> st(n);
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        st.update(i, aux - csum);
        csum = aux;
    }
    for(int i=0;i<m;i++){
        int cur;
        cin >> cur;
        ll qt = st.query(0, cur);
        st.update(cur, -qt);
        if(cur+1 != n) st.update(cur+1, qt);
        st.update(0, qt/n);
        //from cur+1 to ??
        int fst = cur + 1;
        int lst = cur + qt % n;
        if(lst >= fst){
            if(fst != n) st.update(fst, 1);
            if(lst < n){
                if(lst + 1 < n) st.update(lst+1, -1);
            }else{
                st.update(0, 1);
                if((lst%n) + 1 != n) st.update((lst % n) + 1, -1);
            }
        }
    }
    for(int i=0;i<n;i++) cout << st.query(0, i) << " ";
    cout << "\n";
}

