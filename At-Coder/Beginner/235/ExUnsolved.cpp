//at 2n components.
//each new edge makes a new component, tree (at  most n-1 new edges) so at most 2n components
//make the tree of components
//try to make a dp, increasing k in each component, dp[i][k] = sum dp[j][k-1] j is in left subtree of some ancestor.

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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 1e5+3;   
int p[N], sz[N], lb[2*N];
int clb;
void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1; lb[i] = i;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    lb[a] = ++clb;
}

const int N = 1e5+1;
Mint dp[501][2*N];
vector<int> adj[2*N];
int vis[2*N];
vector<int> cur;
int vn[2*N];
//in order;
int t = 0;
void dfs(int u){
    vis[u] = 1;
    if(adj[u].size()){
        dfs(adj[u][0]);
    }
    vn[++t] = u;
    if(adj[u].size()){
        dfs(adj[u][1]);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    Mint ans = 1;
    int n, m, k;
    cin >> n >> m >> k;
    clb = n;
    vector<pair<int,int>, int>> vp(m);
    for(int i=0;i<m;i++){
        cin >> vp[i].first.first >> vp[i].first.second >> vp[i].second;
    }
    sort(vp.begin(), vp.end(), [&](const pair<int,int>, int> &u, const pair<int,int>, int> &v){
        return u.second < v.second;
    });
    for(auto [u, v, w] : vp){
        if(get(u) != get(v)){
            if(sz[get(u)] < sz[get(V)]) swap(u, v);
            lb1 = lb[get(u)];
            lb2 = lb[get(v)];
            
            unite(u, v);
            adj[lb[get(u)]].push_back(lb1);
            adj[lb[get(v)]].push_back(lb2);
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[lb[get(i)]]){
            t = 0;
            dfs(lb[get(i)], 0);
            for(int i=1;i<=k;i++){
                for(int j=1;j<=t;j++){
                    ans += dp[i][j];
                    dp[i][j] = 0;
                }
            }
            for(int i=1;i<=t;i++) vn[i] = 0;
        }
    }
    cout << ans << "\n";

}
