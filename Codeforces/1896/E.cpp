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
        int n;
        cin >> n;
        vector<int> v(n+1), ans(n+1, 0);
        for(int i=1;i<=n;i++) cin >> v[i];
        SegmentTree<int, op, el> st1(n+1), st2(n+1);
        vector<pair<int,int>> ord;
        for(int i=1;i<=n;i++){
            if(v[i] < i){
                st1.update(i, 1);
            }
            if(v[i] != i) ord.push_back({v[i], i});
        }
        sort(ord.begin(), ord.end(), greater<pair<int,int>>());
        //decrescent v[i], i
        for(auto [v1, v2] : ord){
            if(v1 > v2){
                ans[v1] = st1.query(v2+1, v1);
            }else{
                ans[v1] = st1.query(1, v1) + st2.query(v2+1, n); 
                st2.update(v2, 1);
            }
            st1.update(v2, 1);
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
