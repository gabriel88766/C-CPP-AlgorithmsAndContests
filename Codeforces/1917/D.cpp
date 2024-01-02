#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
    //static const int MOD = MOD_val;
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
        if(l >= n) return 0;
        r = min(r, n-1);
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
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> p(n), q(k);
        vector<Mint> sump(21, 0);
        vector<Mint> sump2(21, 0);
        for(int i=1;i<=20;i++){
            for(int j=0;j<k;j++){
                sump[i] += min(k, j+i);
            }
            for(int j=0;j<k;j++){
                sump2[i] += max(0, j-i+1);
            }
        }
        for(int i=0;i<n;i++) cin >> p[i];
        for(int i=0;i<k;i++) cin >> q[i];
        Mint ans = 0;
        //first, number of inversions in q
        SegmentTree<int, op, el> st(max(k, 2*n));
        for(int i=0;i<k;i++) st.update(i, 1);
        Mint inv = 0;
        for(int i=0;i<k;i++){
            st.update(q[i], 0);
            inv += st.query(0, q[i]);
        }
        ans += inv * n;
        for(int i=0;i<n;i++) st.update(2*i+1, 1);
        //now, number of a < b < 2*a, 2a < b < 4*a, etc...
        for(int i=0;i<n;i++){
            st.update(p[i], 0);
            for(int j=1;j<=20;j++){
                ll l = p[i]*(1<<(j-1));
                ll r = p[i]*(1 <<j);
                if(l >= 2*n) break;
                Mint cur = st.query(l, r);
                ans += cur * sump2[j];
            }
            for(int j=1;j<=20;j++){
                Mint cur = st.query(p[i]/(1 <<j)+1, p[i]/(1<<(j-1)));
                ans += cur * sump[j];
            }
            
        }
        cout << ans << "\n";
    }
}
