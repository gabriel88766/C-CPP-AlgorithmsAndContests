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


Mint ans = 0;


const int N = 1002*1002; //substrings of a string of len 1505

int sub[N];
Mint dp[N];
bool fl[N];
int cntn = 0;
int trie[N][2];
int par[N];
int add(int node, char c){
    c -= 'A';
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
void add(string s){
    int curn = 0;
    for(auto c : s){
        int nxtn = add(curn, c);
        par[nxtn] = curn;
        curn = nxtn;
    }
    fl[curn] = true;
    if(trie[curn][0] && trie[curn][1]) dp[curn] = dp[trie[curn][0]] * dp[trie[curn][1]];
    if(fl[curn] && curn) dp[curn] += Mint(2).pow(sub[curn]);
    sub[curn] += 1;
    // cout << dp[curn] << " ";
    while(curn != 0){
        curn = par[curn];
        if(trie[curn][0] != 0 && trie[curn][1] != 0) dp[curn] = dp[trie[curn][0]] * dp[trie[curn][1]];
        else dp[curn] = 0;
        // cout << dp[curn] << " " << trie[curn][0] << " " << trie[curn][1] << "\n";
        if(fl[curn] && curn) dp[curn] += Mint(2).pow(sub[curn]);
        sub[curn] += 1;
    }
    // cout << dp[1] << " " << dp[2] << "\n";
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        add(s);
        cout << dp[0] << "\n";
    }
}
