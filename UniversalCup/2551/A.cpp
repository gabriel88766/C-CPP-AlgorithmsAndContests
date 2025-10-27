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
    Mint(int u){ 
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

vector<int> h;
vector<vector<int>> dc;
vector<vector<int>> adj;

void dfs1(int u, int p){
    h[u] = h[p] + 1;
    int md = 0;
    for(auto v : adj[u]){
        dfs1(v, u);
        md = max(md, (int)dc[v].size());
    }
    dc[u].resize(md + 1);
    dc[u][0] = 1;
    for(auto v : adj[u]){
        for(int j=0;j<dc[v].size();j++){
            dc[u][j+1] += dc[v][j]; 
        }
    }
}

const int N = 500002;
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    if(a < b) return 0;
    return fat[a]*invfat[a-b]*invfat[b];
}

int n, k;
int mh;
const Mint inv = Mint(1)/2;
Mint ans = 0;
int hist[3000];
void dfs2(int u, int p){
    for(int j=1;j<=mh;j++){
        int cur = hist[j];
        if(j < dc[u].size()) cur += dc[u][j];
        ans += nCr(cur, k-1);
    }
    for(int j=mh;j>=1;j--) hist[j] = hist[j-1];
    hist[1] += 1;
    for(auto v : adj[u]){
        for(int j=0;j<dc[v].size();j++){
            hist[j+2] += dc[v][j];
        }
    }
    for(auto v : adj[u]){
        for(int j=0;j<dc[v].size();j++){
            hist[j+2] -= dc[v][j];
        }
        dfs2(v, u);
        for(int j=0;j<dc[v].size();j++){
            hist[j+2] += dc[v][j];
        }
    }
    for(auto v : adj[u]){
        for(int j=0;j<dc[v].size();j++){
            hist[j+2] -= dc[v][j];
        }
    }
    hist[1] -= 1;
    for(int j=0;j<mh;j++) hist[j] = hist[j+1];
    hist[mh] = 0;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        adj.resize(n+1);
        dc.resize(n+1);
        h.resize(n+1);
        h[0] = -1;
        for(int i=2;i<=n;i++){
            int par;
            cin >> par;
            adj[par].push_back(i);
        }
        dfs1(1, 0);
        mh = *max_element(h.begin(), h.end()) * 2 + 2;
        if(k != 1) dfs2(1, 0);
        else ans = n;
        cout << ans << "\n";

        for(int i=1;i<=n;i++){
            adj[i].clear();
            dc[i].clear();
        }
        adj.clear();
        dc.clear();
        h.clear();
        for(int j=0;j<=mh;j++) hist[j] = 0;
        ans = 0;
    }
}   
