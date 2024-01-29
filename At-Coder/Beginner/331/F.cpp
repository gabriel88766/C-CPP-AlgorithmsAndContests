#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <ll MOD_val>
struct Mint{
    ll v;
    static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    Mint pow(ll u){
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
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

using mi1 = Mint<998244353>;
using mi2 = Mint<1000000007>;
using mi3 = Mint<1000000009>;

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

mi1 op1(mi1 a, mi1 b){
    return a + b;
}

mi1 el1(){
    return mi1(0);
}


mi2 op2(mi2 a, mi2 b){
    return a + b;
}

mi2 el2(){
    return mi2(0);
}

mi3 op3(mi3 a, mi3 b){
    return a + b;
}

mi3 el3(){
    return mi3(0);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegmentTree<mi1, op1, el1> st1(n);
    SegmentTree<mi1, op1, el1> st2(n);
    mi1 pot = 1;
    ll pVal = uniform_int_distribution<int>(257, 1000000000)(rng);
    //ll pVal = 26;
    for(int i=0;i<n;i++){
        int val = s[i] - 'a' + 1;
        st1.update(i, pot * val);
        pot *= pVal;
    }
    pot = 1;
    for(int i=n-1;i>=0;i--){
        int val = s[i] - 'a' + 1;
        st2.update(n-i-1, pot * val);
        pot *= pVal;
    }
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            char c;
            cin >> x >> c;
            --x;
            mi1 cur = mi1(pVal).pow(x);
            st1.update(x, cur * (c - 'a' + 1));
            cur = mi1(pVal).pow(n-x-1); 
            st2.update(n-x-1, cur * (c - 'a' + 1));
        }else{
            int l, r;
            cin >> l >> r;
            --l, --r;
            mi1 val1 = st1.query(l, r) / mi1(pVal).pow(l);
            mi1 val2 = st2.query(n-r-1, n-l-1) / mi1(pVal).pow(n-r-1);
            if(val1.v == val2.v) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
