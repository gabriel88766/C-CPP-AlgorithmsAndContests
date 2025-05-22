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
        st.resize(2*n, INF_INT);
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
        st[l] = min(val, st[l]); //assign or increment?
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

const int N = 1e6+2;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v1, v2;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v1.push_back({a, b});
    }
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v2.push_back({a, b});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    SegmentTree<int, op, el> st00(N);
    SegmentTree<int, op, el> st01(N);
    SegmentTree<int, op, el> st10(N);
    SegmentTree<int, op, el> st11(N);
    int p1 = 0, p2 = 0;
    vector<int> ans(m, INF_INT);
    while(p2 < m){
        while(p1 < n && v1[p1].first <= v2[p2].first){
            st00.update(v1[p1].second, -(v1[p1].first + v1[p1].second));
            st01.update(v1[p1].second, -v1[p1].first + v1[p1].second);
            p1++;
        }
        ans[p2] = min(ans[p2], st00.query(1, v2[p2].second) + v2[p2].first + v2[p2].second);
        ans[p2] = min(ans[p2], st01.query(v2[p2].second, 1'000'000) + v2[p2].first - v2[p2].second);
        p2++;
    }
    p1 = n-1, p2 = m-1;
    while(p2 >= 0){
        while(p1 >= 0 && v1[p1].first >= v2[p2].first){
            st10.update(v1[p1].second, v1[p1].first - v1[p1].second);
            st11.update(v1[p1].second, v1[p1].first + v1[p1].second);
            p1--;
        }
        ans[p2] = min(ans[p2], st10.query(1, v2[p2].second) - v2[p2].first + v2[p2].second);
        ans[p2] = min(ans[p2], st11.query(v2[p2].second, 1'000'000) - v2[p2].first - v2[p2].second);
        p2--;
    }
    cout << *max_element(ans.begin(), ans.end()) << "\n";
}
