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


const int N = 2030;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
int cmpnum[N];
char visc[N];

// for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
void tarjan(int u){ //SCC, cmp is in inverse topological order 
    dfs_low[u] = dfs_num[u] = ++cntT;
    visc[u] = 1;
    curcmp.emplace_back(u);
    for(auto v : adj[u]){
        if(!dfs_num[v]) tarjan(v);
        if(visc[v] == 1) dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++cntCmp;
        while(true){
            int v = curcmp.back(); curcmp.pop_back(); visc[v] = 2;
            cmp[cntCmp].emplace_back(v);
            cmpnum[v] = cntCmp;
            if(v == u) break;
        }
    }
}

vector<int> adj2[N];
Mint dp[N][N];
int m;
void dfs(int u){
    if(adj2[u].size() == 0){
        for(int i=1;i<=m;i++) dp[u][i] = 1;
    }else{
        for(auto v : adj2[u]) dfs(v);
        vector<Mint> av(adj2[u].size());
        for(int i=1;i<=m;i++){
            Mint cur = 1;
            for(int j=0;j<adj2[u].size();j++){
                av[j] += dp[adj2[u][j]][i];
                cur *= av[j];
            }
            dp[u][i] = cur;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x == i) continue;
        adj[x].push_back(i);
    }
    for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
    set<pair<int,int>> ajc;
    for(int i=1;i<=n;i++){
        for(auto v : adj[i]){
            if(cmpnum[i] != cmpnum[v]){
                ajc.insert({cmpnum[i], cmpnum[v]});
            }
        }
    }
    vector<bool> hp(cntCmp+1, false);
    for(auto [x, y] : ajc){
        adj2[x].push_back(y);
        hp[y] = true;
    }
    Mint ans = 1;
    for(int i=1;i<=cntCmp;i++){
        if(!hp[i]){
            dfs(i);
            Mint cur = 0;
            for(int j=1;j<=m;j++) cur += dp[i][j];
            ans *= cur;
        }
    }
    cout << ans << "\n";
}   
