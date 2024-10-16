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
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, 0);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p] += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    ll query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, T val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T val){
        update(i, j, val, 0, n-1, 1);
    }
};

int op(int a, int b){
    return max(a, b);
}

int el(){
    return 0;
}

const int N = 2e5+3;
int lf[N]; 
void sieve(){
    for(ll i=2; i<N; i++){
        if(!lf[i]){
            for(ll j = i; j < N; j += i){
                if(!lf[j]) lf[j] = i; 
            }
        }
    }
}

vector<int> adj[N];
vector<pair<int,int>> adjf[N];
vector<pair<int,int>> chp[N];
int sub[N];
int ord[N];
int cnt = 0;
void dfs(int u, int p = 0){
    ord[u] = ++cnt;
    sub[u] = 1;
    for(int i=0;i<adj[u].size();i++){
        auto v = adj[u][i];
        auto [d, c] = adjf[u][i];
        if(v != p){
            dfs(v, u);
            //for v
            while(d != 1){
                chp[lf[d]].push_back({v, -1}); //subtract
                d /= lf[d]; 
            }
            while(c != 1){
                chp[lf[c]].push_back({v, 1});
                c /= lf[c];
            }
            sub[u] += sub[v];
        }
    }
}

Mint fs;
Mint ans;

void dfs_solve(int u, Mint cur, int p = 0){
    ans += cur;
    for(int i=0;i<adj[u].size();i++){
        auto v = adj[u][i];
        auto [d, c] = adjf[u][i];
        if(v != p){
            Mint nxt = cur * Mint(d) / Mint(c);
            dfs_solve(v, nxt, u);
            //for v
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            adj[a].push_back(b);
            adj[b].push_back(a);
            adjf[a].push_back({d, c});
            adjf[b].push_back({c, d});
        }
        dfs(1);
        SegmentTreeLazy<int, op, el> st(n+1);
        ans = 0;
        fs = 1;
        for(int i=1;i<=n;i++){
            if(chp[i].size()){
                for(auto [u, x] : chp[i]){
                    st.update(ord[u], ord[u] + sub[u] - 1, x);
                }
                fs *= Mint(i).pow(st.query(1, n));
                for(auto [u, x] : chp[i]){
                    st.update(ord[u], ord[u] + sub[u] - 1, -x);
                }
            }
        }
        dfs_solve(1, fs);
        cout << ans << "\n";
        cnt = 0;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            adjf[i].clear();
            chp[i].clear();
        }
    }
}
