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

const int N = 2e5+3;   
int p[N], sz[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
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
int par[N], sub[N];

void dfs(int u, int p){
    par[u] = p;
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        init(n);
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            unite(a, b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        set<int> s;
        Mint prd = 1;
        for(int i=1;i<=n;i++){
            if(!s.count(get(i))){
                s.insert(get(i));
                prd *= sz[get(i)];
            }
        }
        dfs(n, 0);
        int ssz = s.size();
        if(get(n-1) == get(n)){
            
            int x = n-1;
            
            while(par[x] != n) x = par[x];
            for(int i=1;i<n;i++){
                if(i == x){
                    cout << Mint(n).pow(ssz - 2) * prd << " ";
                }
                else cout << "0 ";
            }
            cout << "\n";
        }else{
            for(int i=1;i<n;i++){
                if(get(i) == get(n)){
                    if(par[i] == n){
                        cout << Mint(n).pow(ssz - 2) * prd * Mint(sub[i]) / sz[get(i)] << " ";
                    }else cout << "0 ";
                }else if(get(i) == get(n-1)){
                    cout << Mint(n).pow(ssz-3) * ((prd / sz[get(n)]) / sz[get(i)]) * Mint(sz[get(n)] + sz[get(i)]) << " ";
                }else{
                    cout << Mint(n).pow(ssz-3) * ((prd)/sz[get(n)]) << " ";
                }
            }
            cout << "\n";
        }


        for(int i=1;i<=n;i++){
            par[i] = 0;
            sub[i] = 0;
            adj[i].clear();
        }
    }
}