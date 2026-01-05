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
    return a ^ b;
}

int el(){
    return 0;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
        const int HASH = 2;
        vector<vector<int>> hsh(n+1, vector<int>(HASH));
        SegmentTree<int, op, el> st1(2*n+1), st2(2*n+1), st3(2*n+1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<HASH;j++){
                hsh[i][j] = uniform_int_distribution<int>(1,100000000)(rng);
            }
        }
        int oh1 = 0, oh2 = 0;
        for(int i=1;i<=n;i++){
            int l, r;
            cin >> l >> r;
            //from l+1 to r-1 
            int qnt = st1.query(l+1, r-1);
            int h1 = st2.query(l+1, r-1);
            int h2 = st3.query(l+1, r-1);
            int dqnt = qnt ? 0 : 1;
            int t1 = dqnt * hsh[i][0];
            int t2 = dqnt * hsh[i][1];
            int dsh1 = h1 ^ t1;
            int dsh2 = h2 ^ t2;
            oh1 ^= dsh1;
            oh2 ^= dsh2;
            if(oh1 == 0 && oh2 == 0) cout << "1";
            else cout << "0";
            st1.update(l, dqnt);
            st1.update(r, dqnt);
            st2.update(l, dsh1);
            st2.update(r, dsh1);
            st3.update(l, dsh2);
            st3.update(r, dsh2);
            
        }
        cout << "\n";
    }
}
