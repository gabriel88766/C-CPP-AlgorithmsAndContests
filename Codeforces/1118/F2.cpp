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
        if(u < 0) return (Mint(1)/v).pow(-u);
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

const int N = 3e5+3, M = 20;  
int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
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
}


vector<int> adj[N];
int cl[N], h[N], val[N], par[N];
vector<int> sc[N];
int anc[N][M];


void dfs(int u, int p){
    anc[u][0] = p;
    h[u] = h[p] + 1;
    par[u] = p;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
}

int lca(int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) b = anc[b][i];
    if(a == b) return a;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}


void dfs2(int u, int p){
    for(auto v : adj[u]){
        if(v != p){
            dfs2(v, u);
            val[u] += val[v];
        }
    }
    if(val[u] != 0) unite(u, p);
}

Mint ans = 1;
Mint dp[N][2];
int xx;
void dfs3(int u, int p){
    bool lf = true;
    if(p == xx || cl[u] == 0){
        for(auto v : adj[u]){
            if(v != p){
                dfs3(v, u);
                lf = false;
            }
        }
        
    }
    if(lf){
        if(cl[u] != 0 && p != xx){
            dp[u][0] = 0;
            dp[u][1] = 1;
        }else{
            dp[u][1] = 0;
            dp[u][0] = 1; 
        }
    }else{
        dp[u][0] = 1;
        for(auto v : adj[u]){
            if(v != p){
                dp[u][0] *= (dp[v][0] + dp[v][1]);
            }
        }
        for(auto v : adj[u]){
            if(v != p){
                dp[u][1] += (dp[u][0] / (dp[v][0] + dp[v][1])) * dp[v][1];
            }
        }
    }

}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, k;
    cin >> n >> k;
    int rt = -1;
    for(int i=1;i<=n;i++){
        cin >> cl[i];
        if(cl[i] != 0) sc[cl[i]].push_back(i);
        if(cl[i] != 0 && rt == -1) rt = i;
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    h[0] = -1;
    dfs(rt, 0);
    for(int j = 1; j < M; j++){
        for(int i=1;i<=n;i++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=k;i++){
        int lc = sc[i][0];
        for(int j=1;j<sc[i].size();j++){
            int nlc = lca(lc, sc[i][j]);
            val[lc]+=1;
            val[sc[i][j]] += 1;
            val[nlc] -= 2;
        }
    }
    dfs2(rt, 0);
    vector<vector<int>> bcp(n+1);
    for(int i=1;i<=n;i++) bcp[get(i)].push_back(i);
    bool ok = true;
    for(int i=1;i<=n;i++){
        int pc = -1;
        for(auto x : bcp[i]){
            if(cl[x] != 0){
                if(pc == -1) pc = cl[x];
                else if(pc != cl[x]){
                    ok = false;
                }
            }
        }
        if(pc != -1) for(auto x : bcp[i]) cl[x] = pc;
    }
    if(!ok) cout << "0\n";
    else{
        // cout << rt << "\n";
        for(int i=1;i<=n;i++){
            if(cl[i]){
                xx = par[i];
                dfs3(i, par[i]);
                // cout << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
                ans *= dp[i][0];
            }
        }
        cout << ans << "\n";
    }
}       
