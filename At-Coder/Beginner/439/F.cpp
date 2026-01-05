#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

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

Mint opm(Mint a, Mint b){
    return a + b;
}
Mint elm(){
    return Mint(0);
}


const int N = 3e5+5;
Mint pt2[N], ipt2[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    pt2[0] = 1;
    ipt2[0] = 1;
    Mint inv = Mint(1)/2;
    for(int i=1;i<N;i++){
        pt2[i] = pt2[i-1];
        ipt2[i] = ipt2[i-1];
        pt2[i] *= 2;
        ipt2[i] *= inv;
    }
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    SegmentTree<int, op, el> st(n+1);
    SegmentTree<Mint, opm, elm> st2(n+1);
    for(int i=n;i>=1;i--){
        Mint cur = st.query(1, p[i]);
        cur *= pt2[i];
        st2.update(i, cur);
        st.update(p[i], st.query(p[i], p[i]) + 1);
    }
    SegmentTree<int, op, el> st3(n+1);
    Mint ans = 0;
    for(int i=1;i<n;i++){
        Mint cur = st3.query(1, p[i]);
        // cout << i << " " << cur << " ";
        cur *= ipt2[i+1];
        // cout << cur << " " << st2.query(i+1, n) << "\n";
        ans += cur * st2.query(i+1, n);
        ans += cur * st2.query(i, i) * 2;
        st3.update(p[i], st3.query(p[i], p[i]) + 1);
    }
    cout << ans << "\n";
}
