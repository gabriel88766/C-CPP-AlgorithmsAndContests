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
    ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
        if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
            x = 1; y = 0;
            return a;
        }
        ll d = gcd_euclid(b, a % b, y, x); //if b > a then this step reverses it
        y -= x * (a/b); 
        return d;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    /*Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}*/
    Mint operator/= (Mint u){ //division , MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
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

Mint op(Mint a, Mint b){
    return a + b;
}

Mint el(){
    return Mint(0);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;
        int q;
        cin >> q;
        vector<Mint> p2(n+1);
        for(int i=0;i<=n;i++) p2[i] = Mint(2).pow(i);
        vector<SegmentTree<Mint, op, el>> st(2, SegmentTree<Mint, op, el>(n+1));
        vector<SegmentTree<Mint, op, el>> stt(2, SegmentTree<Mint, op, el>(n+1));
        //j = 0, 0, j = 1, 1;
        
        for(int j=0;j<2;j++){
            for(int k=1;k<=n;k++){
                if(j != s[k]-'0') continue;
                int x = k-1;
                st[j].update(k, p2[x]);
            }
        }
        
        Mint ans = 0;
        for(int i=1;i<=n;i++){
            ans += p2[n-i];
            if(s[i] == '1'){
                //01
                ans += st[0].query(0, i) * p2[n-i];
                stt[1].update(i, p2[n-i]);
            }else{
                ans += st[1].query(0, i) * p2[n-i];
                stt[0].update(i, p2[n-i]);
            }
        }
        for(int i=1;i<=q;i++){
            int x;
            cin >> x;
            if(s[x] == '1'){
                stt[1].update(x, 0);
                st[1].update(x, 0);
                ans -= st[0].query(1, x) * p2[n-x];
                ans -= stt[0].query(x, n) * p2[x-1];
                s[x] = '0';
                ans += st[1].query(1, x) * p2[n-x];
                ans += stt[1].query(x, n) * p2[x-1];
                st[0].update(x, p2[x-1]);
                stt[0].update(x, p2[n-x]);
            }else{
                stt[0].update(x, 0);
                st[0].update(x, 0);
                ans -= st[1].query(1, x) * p2[n-x];
                ans -= stt[1].query(x, n) * p2[x-1];
                s[x] = '1';
                ans += st[0].query(1, x) * p2[n-x];
                ans += stt[0].query(x, n) * p2[x-1];
                st[1].update(x, p2[x-1]);
                stt[1].update(x, p2[n-x]);
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}   
