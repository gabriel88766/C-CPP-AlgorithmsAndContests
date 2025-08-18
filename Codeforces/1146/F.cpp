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

const int N = 2e5+3;
vector<int> adj[N];
Mint dp1[N], dp2[N];
Mint aux[3];
Mint naux[3];

void dfs(int u){
    if(adj[u].size() == 0){
        dp1[u] = 1, dp2[u] = 0;
    }else{
        for(auto v : adj[u]){
            dfs(v);
        }
        aux[0] = aux[1] = aux[2] = 0;
        aux[0] = 1;
        for(auto v : adj[u]){
            naux[2] = aux[2] * (dp1[v] + 2*dp2[v] + 1) + aux[1] * (dp1[v] + dp2[v]);
            naux[1] = aux[1] * (dp2[v] + 1) + aux[0] * (dp2[v] + dp1[v]);
            naux[0] = aux[0] * (dp2[v] + 1);
            aux[0] = naux[0];
            aux[1] = naux[1];
            aux[2] = naux[2];
            dp1[u] += dp1[v];
            cout << u << " " << dp1[v] << " " << dp2[v] << "\n";
        }
        dp2[u] = aux[2] + aux[0] - 1;
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        int px;
        cin >> px;
        adj[px].push_back(i);
    }
    dfs(1);
    cout << dp2[1] + 1 << "\n";
}
