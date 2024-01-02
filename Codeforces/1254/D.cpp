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

const int N = 150005;
vector<int> adj[N];
vector<tuple<int,int,int>> qrs[N];
int sub[N];
int par[N];
int ord[N];

void dfs1(int u, int p){
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
    
}

int ct = 0;
void dfs2(int u, int p){
    ord[u] = ++ct;
    int csz = -1, bg = -1;
    for(auto v : adj[u]){
        if(v == p) continue;
        if(sub[v] != csz){
            if(csz != -1){
                qrs[u].push_back({bg, ct, csz});
            }
            csz = sub[v];
            bg = ct + 1;
        }
        dfs2(v, u);
    }
    if(csz != -1) qrs[u].push_back({bg, ct, csz});
}

const int sqrtN = 400; //200000 = 500*400
Mint v[N];
Mint bl[N/sqrtN+1];
int n;
 
Mint query(int a, int b){
    int l = (a/sqrtN+1)*sqrtN;
    int r = (b/sqrtN)*sqrtN;
    Mint ans = 0;
    if(r <= l){
        for(int i=a;i<=b;i++) ans += v[i];
    }else{
        for(int i=a;i<l;i++) ans += v[i];
        for(int i=r;i<=b;i++) ans += v[i];
        l /= sqrtN, r /= sqrtN;
        for(int i=l;i<r;i++){
            ans += bl[i];
        }
    }
    return ans;
}

void update(int pos, Mint val){ //PURS
    bl[pos/sqrtN] += val;
    v[pos] += val;
}
void update(int l, int r, Mint val){
    if(l > r) return;
    update(l, val);
    if(r < n) update(r+1, MOD-val);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    for(int u=1;u<=n;u++){
        sort(adj[u].begin(), adj[u].end(), [&](int a, int b){
            return sub[a] < sub[b];
        });
    }
    dfs2(1, 0);
    Mint inv = Mint(1)/n;
    for(int i=1;i<=q;i++){
        int t, a;
        Mint d;
        cin >> t >> a;
        if(t == 1){
            cin >> d.v;
            for(auto [l, r, sz] : qrs[a]){
                update(l, r, d*inv*(n-sz));
            }
            update(1, ord[a]-1, d*inv*sub[a]);
            update(ord[a]+sub[a], n, d*inv*sub[a]);
            update(ord[a], ord[a], d);
        }else{
            cout << query(1, ord[a]) << "\n";
        }
    }
}
