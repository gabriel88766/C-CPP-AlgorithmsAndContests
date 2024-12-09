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
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1), b(n+1), p(n+1), q(n+1);
    int tta = 0, ttb = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        tta += a[i];
    }
    for(int i=1;i<=n;i++){
         cin >> b[i];
         ttb += b[i];
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        p[x] = i;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        q[x] = i;
    }
    vector<int> vp, vq;
    int cur = x;
    int sa = a[x];
    while(sa != tta && p[cur] != x){
        cur = p[cur];
        vp.push_back(cur);
        sa += a[cur];
    }
    cur = x;
    int sb = b[x];
    while(sb != ttb && q[cur] != x){
        cur = q[cur];
        vq.push_back(cur);
        sb += b[cur];
    }
    if(sa != tta || sb != ttb) cout << "-1\n";
    else{
        reverse(vp.begin(), vp.end());
        reverse(vq.begin(), vq.end());
        vector<int> mp(n+1);
        SegmentTree<int, op, el> st(n+1);
        for(int i=0;i<vq.size();i++){
            mp[vq[i]] = i + 1;
        }
        int aux = 0;
        for(int i=0;i<vp.size();i++){
            if(mp[vp[i]]){
                st.update(mp[vp[i]], st.query(1, mp[vp[i]]) + 1);
                aux = max(aux, st.query(mp[vp[i]], mp[vp[i]]));
            }
        }
        int ans = vp.size() + vq.size();
        ans -= aux;
        cout << ans << "\n";
    }


}
