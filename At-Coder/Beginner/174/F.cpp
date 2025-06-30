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

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}

const int N = 5e5+3;
vector<int> ocn[N];
int v[N], ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    SegmentTree<int, op, el> st(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(ocn[v[i]].size() == 0){
            st.update(i, 1);
        }
        ocn[v[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) reverse(ocn[i].begin(), ocn[i].end());
    vector<tuple<int, int, int>> qr;
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        qr.push_back({a, b, i});
    }
    sort(qr.begin(), qr.end());
    int p = 1;
    for(auto [a, b, j] : qr){
        while(p < a){
            st.update(ocn[v[p]].back(), 0);
            ocn[v[p]].pop_back();
            if(ocn[v[p]].size()){
                st.update(ocn[v[p]].back(), 1);
            }
            p++;
        }
        ans[j] = st.query(a, b);
    }

    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
}
