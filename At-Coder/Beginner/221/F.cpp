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
    vector<T> st;
    vector<int> lz;
    int n;
    SegmentTreeLazy(vector<int> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, nullel());
        lz.assign(4*n, 0);
    }
    void build(vector<int> &v, int l, int r, int p){
        if(l == r){ st[p] = {v[l], 1}; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p].first += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, int val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, int val){
        update(i, j, val, 0, n-1, 1);
    }
};

pair<int, int> op(pair<int, int>  a, pair<int, int>  b){
    if(a.first == b.first) return make_pair(a.first, a.second + b.second);
    else if(a < b) return b;
    else return a;
}

pair<int, int> el(){
    return make_pair(0, 0);
}


const int N = 2e5+3;
vector<int> adj[N];
int dst[N], n, cnt;
int sub[N], h[N], ord[N], par[N];

void bfs(int src){
    queue<int> q;
    q.push(src); 
    dst[src] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : adj[u]){
            if(dst[u] + 1 < dst[v]){
                dst[v] = dst[u] + 1; q.push(v);
            }
        }
    }
}

int diameter(){ //node first to second is the diameter.
    memset(dst, 63, sizeof(dst));
    bfs(1);
    int fart1 = 1, maxd = 0, fart2 = 1;
    for(int i=2;i<=n;i++) if(dst[i] > maxd) maxd = dst[i], fart1 = i;
    memset(dst, 63, sizeof(dst));
    bfs(fart1);
    maxd = 0;
    for(int i=1;i<=n;i++) if(dst[i] > maxd) maxd = dst[i], fart2 = i;
    return maxd;
}

void dfs(int u, int p){
    par[u] = p;
    h[u] = h[p] + 1;
    sub[u] = 1;
    ord[u] = ++cnt;
    for(auto &v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}
int d;
SegmentTreeLazy<pair<int,int>, op, el> st(0);
Mint solve1(int u){
    Mint ans = 0;
    auto qr = st.query(0, n);
    if(qr.first == d) ans += qr.second;
    for(auto &v : adj[u]){
        if(v != par[u]){
            st.update(1, n, 1);
            st.update(ord[v], ord[v] + sub[v] - 1, -2);
            ans += solve1(v);
            st.update(1, n, -1);
            st.update(ord[v], ord[v] + sub[v] - 1, 2);
        }
    }
    return ans;
}

Mint solve2(int u){
    Mint ans = 0;
    int md = st.query(0, n).first;
    if(md == d/2){ //center!!
        int sd = 0;
        vector<int> ad;
        for(auto &v : adj[u]){
            if(v != par[u]){
                auto qr = st.query(ord[v], ord[v] + sub[v] - 1);
                if(qr.first == md){
                    sd += qr.second;
                    ad.push_back(qr.second);
                }
            }
        }
        auto qr = st.query(0, n);
        if(qr.second - sd > 0) ad.push_back(qr.second - sd);
        if(ad.size() >= 3){
            vector<Mint> dp(4);
            dp[0] = 1;
            for(auto &x : ad){
                dp[3] = dp[3] * (x + 1) + dp[2] * x;
                dp[2] = dp[2] + dp[1] * x;
                dp[1] = dp[1] + dp[0] * x;
                // cout << dp[0] << " " << dp[1] << " " << dp[2] << " " << dp[3] << "\n";
            }
            ans += dp[3];
        }
    }
    for(auto &v : adj[u]){
        if(v != par[u]){
            st.update(1, n, 1);
            st.update(ord[v], ord[v] + sub[v] - 1, -2);
            ans += solve2(v);
            st.update(1, n, -1);
            st.update(ord[v], ord[v] + sub[v] - 1, 2);
        }
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    d = diameter();
    h[0] = -1;
    dfs(1, 0);
    Mint ans = 0;
    vector<int> vx(n+1);
    vx[0] = -INF_INT;
    for(int i=1;i<=n;i++){
        vx[ord[i]] = h[i];
    }
    st = SegmentTreeLazy<pair<int,int>, op, el>(vx);
    ans += solve1(1)/2;
    if(!(d % 2)) ans += solve2(1);
    cout << ans << "\n";
}
