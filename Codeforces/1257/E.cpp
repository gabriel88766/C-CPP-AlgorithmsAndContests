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
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> da(a), db(b), dc(c);
    for(int i=0;i<a;i++) cin >> da[i];
    for(int i=0;i<b;i++) cin >> db[i];
    for(int i=0;i<c;i++) cin >> dc[i];
    sort(da.begin(), da.end());
    sort(db.begin(), db.end());
    sort(dc.begin(), dc.end());
    int n = a + b + c;
    SegmentTree<int, op, el> st(n+2);
    st.update(n+1, dc.size());
    int cur = dc.size();
    int p3 = dc.size() - 1, p1 = da.size() - 1;
    for(int i=n;i>=1;i--){
        if(p3 >= 0 && dc[p3] == i) cur--, p3--;
        else if(p1 >= 0 && da[p1] == i) p1--;
        else cur++;
        // cout << cur << " ";
        st.update(i, cur);
    }
    // cout << "\n";
    int op1 = da.size();
    int ans = n;
    p1 = 0, p3 = 0;
    for(int i=0;i<=n;i++){
        if(p1 < da.size() && da[p1] == i){
            op1--, p1++;
        }else if(p3 < dc.size() && dc[p3] == i){
            p3++;
        }else if(i) op1++;
        ans = min(ans, op1 + st.query(i+1, n+1));
        // cout << op1  << " " << st.query(i+1, n+1) << "\n";
    }
    cout << ans << "\n";
}
