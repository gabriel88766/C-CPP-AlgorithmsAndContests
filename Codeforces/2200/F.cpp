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

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}
ll op2(ll a, ll b){
    return max(a, b);
}
ll el2(){
    return 0LL;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<tuple<int, int, int>> vt;
        vector<pair<int, int>> v1;
        for(int i=1;i<=n;i++){
            int x, y;
            cin >> x >> y;
            v1.push_back({x, i});
            vt.push_back({y, x, i});
        }
        sort(v1.begin(), v1.end(), greater<pair<int, int>>());
        vector<int> ord(n+1);
        for(int i=0;i<n;i++){
            ord[v1[i].second] = i+1;
        }
        sort(vt.begin(), vt.end(), greater<tuple<int, int, int>>());
        SegmentTree<ll, op, el> st1(n+1), st2(n+1);
        vector<ll> val1(n+1), val2(n+1);
        int p1 = 0, p2 = n;
        for(int i=n;i>=0;i--){
            while(p1 < vt.size() && get<0>(vt[p1]) == i){
                st1.update(ord[get<2>(vt[p1])], 1);
                st2.update(ord[get<2>(vt[p1])], get<1>(vt[p1]));
                p1++;
            }
            while(st1.query(0, p2) > i+1) p2--;
            val1[i] = st2.query(0, p2);
            while(st1.query(0, p2) > i) p2--;
            val2[i] = st2.query(0, p2);
        }
        ll ans = 0;
        for(int i=0;i<=n;i++) ans = max(ans, val1[i]);
        SegmentTree<ll, op2, el2> st3(val2);
        for(int i=1;i<=m;i++){
            int x, y;
            cin >> x >> y;
            ll cans = max(ans, x + st3.query(0, y));
            cout << cans << " ";
        }
        cout << "\n";
    }
}
