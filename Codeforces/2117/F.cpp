#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //
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
vector<int> adj[N];
int ttc[N], sub[N], par[N];
void dfs1(int u, int p = 0){
    int cc = 0;
    par[u] = p;
    sub[u] = 1;
    for(auto &v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
            cc++;
        }
    }
    ttc[u] = cc;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs1(1);
        bool ok = true;
        int nd = -1;
        for(int i=1;i<=n;i++){
            if(ttc[i] > 1){
                if(ttc[i] == 2){
                    if(nd == -1) nd = i;
                    else ok = false;
                }else ok = false;
            }
        }
        if(!ok){
            cout << "0\n";
        }else if(nd == -1){
            cout << Mint(2).pow(n) << "\n";
        }else{
            vector<int> vals;
            int ttup = sub[1] - sub[nd] + 1;
            for(auto &v : adj[nd]){
                if(v != par[nd]) vals.push_back(sub[v]);
            }
            assert(vals.size() == 2);
            int mn = min(vals[0], vals[1]);
            int mx = max(vals[0], vals[1]);
            Mint ans;
            if(mx == mn) ans = 2;
            else ans = Mint(2).pow(mx - mn) + Mint(2).pow(mx - mn - 1);
            ans *= Mint(2).pow(ttup);
            cout << ans << "\n";
        }
        
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }
}
