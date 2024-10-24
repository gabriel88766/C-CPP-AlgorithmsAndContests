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
    return max(a, b);
}

int el(){
    return 0;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v1(n), v2(m+1);
    for(int i=0;i<n;i++) cin >> v1[i].first;
    for(int i=0;i<n;i++) cin >> v1[i].second;
    for(int i=1;i<=m;i++) cin >> v2[i].first;
    for(int i=1;i<=m;i++) cin >> v2[i].second;
    sort(v1.begin(), v1.end(), [&](pair<int,int> &u, pair<int,int> &v){
        return u.second > v.second;
    });
    sort(v2.begin(), v2.end());
    SegmentTree<int, op, el> st(m+1);
    for(int i=1;i<=m;i++) st.update(i, v2[i].second);
    bool ok = true;
    for(int i=0;i<n;i++){
        auto it = lower_bound(v2.begin(), v2.end(), make_pair(v1[i].first, 0));
        if(it == v2.end()){
            ok = false;
            break;
        }
        int ind = it - v2.begin();
        // cout << ind << " " << st.query(ind, m) << " " << v1[i].second << "\n";
        if(st.query(ind, m) >= v1[i].second){
            //then ok.
            int r = m;
            for(int j=(m-ind);j>=1;j>>=1){
                while(r-j >= ind && st.query(ind, r - j) >= v1[i].second) r -= j;
            }
            st.update(r, 0);
        }else{
            ok = false;
            break;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}   
