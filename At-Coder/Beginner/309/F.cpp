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
    return min(a, b);
}

int el(){
    return INF_INT;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<tuple<int, int, int>> vt(n);
    vector<int> cd;
    for(int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a < b) swap(a, b);
        if(a < c) swap(a, c);
        if(b < c) swap(b, c);
        assert(a >= b && b >= c);
        vt[i] = {a, b, c};
        cd.push_back(b);
    }
    sort(cd.begin(), cd.end());
    cd.resize(unique(cd.begin(), cd.end()) - cd.begin());
    vector<int> aux(cd.size(), INF_INT);
    SegmentTree<int, op, el> st(aux);
    sort(vt.begin(), vt.end());
    queue<tuple<int, int, int>> qadd;
    bool ok = false;
    for(auto [a, b, c] : vt){
        qadd.push({a, b, c});
        while(get<0>(qadd.front()) < a){
            auto [nnn, x, y] = qadd.front();
            qadd.pop();
            //ADD to segment tree.
            auto idx = lower_bound(cd.begin(), cd.end(), x) - cd.begin();
            if(st.query(idx, idx) > y) st.update(idx, y);
        }
        //check if in segment tree
        auto idx = lower_bound(cd.begin(), cd.end(), b) - cd.begin();
        if(idx == 0) continue;
        if(st.query(0, idx - 1) < c) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
