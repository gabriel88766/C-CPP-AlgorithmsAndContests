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

char gr[205][205];
char fr[205][205];
vector<string> v;
vector<int> adj[24577];
int h, w;
void genall(string cur){
    if(cur.size() == w){
        v.push_back(cur);
        return;
    }
    for(char j='1';j<='3';j++){
        if(cur == "" || cur.back() != j) genall(cur + j);
    }
}
int tt = 0;
void genall2(){
    map<string, int> mp;
    for(int i=0;i<v.size();i++) mp[v[i]] = i;
    for(int i=0;i<v.size();i++){
        vector<string> nw;
        nw.push_back("");
        for(int j=0;j<w;j++){
            vector<string> nv;
            for(auto x : nw){
                for(char k='1';k<='3';k++){
                    if(x.size() && x.back() == k) continue;
                    if(v[i][j] == k) continue;
                    nv.push_back(x + k);
                }
            }
            nw = nv;
        }
        for(auto x : nw) adj[i].push_back(mp[x]);
        tt += adj[i].size();
    }
}
Mint dp[205][24577];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> h >> w;
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> gr[i][j];
    if(h < w){
        for(int i=0;i<h;i++) for(int j=0;j<w;j++) fr[j][i] = gr[i][j];
        swap(h, w);
    }else{
        for(int i=0;i<h;i++) for(int j=0;j<w;j++) fr[i][j] = gr[i][j];
    }
    genall("");
    genall2();
    for(int i=0;i<h;i++){
        if(i == 0){
            for(int j=0;j<v.size();j++){
                bool ok = true;
                for(int u=0;u<v[j].size();u++){
                    if(v[j][u] != fr[i][u] && fr[i][u] != '?') ok = false;
                }
                if(ok) dp[i][j] = 1;
            }
        }else{
            vector<bool> ok(v.size());
            for(int j=0;j<v.size();j++){
                ok[j] = true;
                for(int u=0;u<v[j].size();u++){
                    if(v[j][u] != fr[i][u] && fr[i][u] != '?') ok[j] = false;
                }
            }
            for(int j=0;j<v.size();j++){
                for(auto jj : adj[j]){
                    if(ok[jj]) dp[i][jj] += dp[i-1][j];
                }
            }
        }
    }
    Mint ans = 0;
    for(int j=0;j<v.size();j++) ans += dp[h-1][j];
    cout << ans << "\n";
}
