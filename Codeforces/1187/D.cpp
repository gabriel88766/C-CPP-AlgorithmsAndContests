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

int opmn(int a, int b){
    return min(a, b);
}

int elmn(){
    return INF_INT;
}

int opmx(int a, int b){
    return max(a, b);
}

int elmx(){
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
        vector<vector<int>> rvo(n+1);
        vector<int> a(n+1), b(n+1), pos(n+1), invp(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int j=1;j<=n;j++) cin >> b[j];
        for(int i=n;i>=1;i--){
            rvo[b[i]].push_back(i);
        }
        bool ok = true;
        for(int i=1;i<=n;i++){
            if(rvo[a[i]].size()){
                pos[i] = rvo[a[i]].back();
                invp[pos[i]] = i;
                rvo[a[i]].pop_back();
            }else ok = false;
        }
        if(ok){
            // SegmentTree<int, opmn, elmn> stmn(a);
            SegmentTree<int, opmx, elmx> stmx(n+1);
            SegmentTree<int, opmn, elmn> stmn(n+1);
            for(int k=1;k<=n;k++){
                //pos[i] = k, increasing order, check if some j > i, a[j] >= a[i]
                int i = invp[k];
                if(stmx.query(i, n) >= a[i]) ok = false;
                stmx.update(i, a[i]);
            }
            for(int i=1;i<=n;i++) stmn.update(i, INF_INT);
            
            for(int k=n;k>=1;k--){
                //pos[i] = k, decreasing order, check if some j < i, a[j] <= a[i];
                int i = invp[k];
                if(stmn.query(1, i) <= a[i]) ok = false;
                stmn.update(i, a[i]);
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";

        }else cout << "NO\n";
    }
}
