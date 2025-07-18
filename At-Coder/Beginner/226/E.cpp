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

const int N = 2e5+3;
set<int> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<int> q;
    for(int i=1;i<=n;i++){
        if(adj[i].size() == 1) q.push_back(i);
    }
    bool ok = true;
    if(n != m) ok = false;
    while(q.size()){
        int u = q.back();
        q.pop_back();
        if(adj[u].size() == 0){
            ok = false;
            break;
        }
        int v = *adj[u].begin();
        adj[u].clear();
        adj[v].erase(u);
        if(adj[v].size() == 1){
            q.push_back(v);
        }else if(adj[v].size() == 0){
            //oh no...
            ok = false;
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size() != 0 && adj[i].size() != 2) ok = false;
    }
    if(ok){
        vector<bool> vis(n+1);
        Mint ans = 1;
        for(int i=1;i<=n;i++){
            if(adj[i].size() == 2 && vis[i] == false){
                ans *= 2;
                int cur = i, par = 0;
                while(!vis[cur]){
                    vis[cur] = true;
                    if(*adj[cur].begin() != par){
                        par = cur;
                        cur = *adj[cur].begin();
                    }else{
                        par = cur;
                        cur = *prev(adj[cur].end());
                    }
                }
            }
        }
        cout << ans << "\n";
    }else cout << "0\n";
    
}
