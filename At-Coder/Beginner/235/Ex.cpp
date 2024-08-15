//at 2n components.
//each new edge makes a new component, tree (at  most n-1 new edges) so at most 2n components
//make the tree of components
//try to make a dp, increasing k in each component, dp[i][k] = sum dp[j][k-1] j is in left subtree of some ancestor.

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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

struct edge{
    int a, b, c;
    bool operator< (const edge &e) const {
        return c < e.c;
    }
};

const int N = 1e5+3;   
int p[N];
Mint dp[N][501];
int n;
void init(){
    for(int i=1;i<=n;i++) {p[i] = i;  dp[i][0] = 1; dp[i][1] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    int x1 = 0, x2 = 0;
    for(int i=0;i<=500;i++) if(dp[a][i] != 0) x1 = i;
    for(int i=0;i<=500;i++) if(dp[b][i] != 0) x2 = i;
    if(x1 < x2){
        swap(x1, x2);
        swap(a, b);
    }
    //merge
    for(int i=min(500, x1+x2);i>=1;i--){
        for(int j=max(1, i-x1);j<=min(i, x2);j++){ //dp[b][j], i-j <= x1 -> j >= i-x1
            dp[a][i] += dp[a][i-j] * dp[b][j];
        }
    }
    p[b] = a;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    Mint ans = 0;
    int m, k;
    cin >> n >> m >> k;
    init();
    vector<edge> v(m);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = {a, b, c};
    }
    sort(v.begin(), v.end());
    int cl = 0;
    int p = 0;
    while(p < m){
        cl = v[p].c;
        set<int> allu;
        int pi = p;
        while(pi < m && v[pi].c == cl){
            allu.insert(get(v[pi].a));
            allu.insert(get(v[pi].b));
            pi++;
        }
        while(p != pi){
            unite(v[p].a, v[p].b);
            p++;
        }
        map<int, int> cc;
        for(auto x : allu){
            cc[get(x)]++;
        }
        for(auto [kk, v] : cc){
            dp[kk][1]+=1;
            if(v <= 500) dp[kk][v]-=1;
        }
    }
    for(int i=2;i<=n;i++){
        if(get(i) != get(1)) unite(i, 1);
    }
    for(int i=0;i<=k;i++) ans += dp[get(1)][i];
    cout << ans << "\n";

}
