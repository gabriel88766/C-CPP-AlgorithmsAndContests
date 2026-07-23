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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<int> d(n+1, INF_INT);
    vector<Mint> dp(n+1, 0);
    dp[1] = 1;
    d[1] = 0;
    queue<int> q;
    q.push(1);
    set<int> unv;
    for(int j=2;j<=n;j++) unv.insert(j);
    while(q.size()){
        auto u = q.front();
        q.pop();
        vector<int> rml;
        for(auto x : unv){
            if(!adj[u].count(x)){
                rml.push_back(x);
                d[x] = d[u] + 1;
                q.push(x);
            }
        }
        for(auto x : rml) unv.erase(x);
    }
    if(d[n] != INF_INT){
        vector<set<int>> lst(n+1);
        for(int i=1;i<=n;i++){
            if(d[i] != INF_INT) lst[d[i]].insert(i);
        }
        for(int i=1;i<=n;i++){
            if(lst[i].size() == 0) break;
            Mint tt = 0;
            for(auto x : lst[i-1]) tt += dp[x];
            for(auto x : lst[i]){
                Mint cur = tt;
                for(auto v : adj[x]){
                    if(lst[i-1].count(v)) cur -= dp[v]; 
                }
                dp[x] = cur;
            }
        }
        cout << dp[n] << "\n";
    }else cout << "-1\n";
}
