#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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

const int N = 2005;
vector<int> adj[N], adjw[N];
int gr[N];
int dp[N][N]; //highest distance after i steps to get to u vertex


struct Seg{
    ll l, r, a, b;
    bool operator<(const Seg &s){
        return l < s.l;
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adjw[a].push_back(c);
        adjw[b].push_back(c);
        gr[a] = max(gr[a], c);
        gr[b] = max(gr[b], c);
    }
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = -INF_INT;
    dp[0][1] = 0;
    for(int i=1;i<=n;i++){//n steps
        for(int u=1;u<=n;u++){
            if(dp[i-1][u] < 0) continue;
            for(int j=0;j<adj[u].size();j++){
                int v = adj[u][j];
                int w = adjw[u][j];
                dp[i][v] = max(dp[i][v], dp[i-1][u] + w);
            }
        }
    }
   
    Mint ans = 0;
    for(int i=1;i<=min(n,q);i++){
        int cur = 0;
        for(int u=1;u<=n;u++){
            cur = max(cur, dp[i][u]);
        }
        ans += cur;
    }
    if(q <= n){
        cout << ans << "\n";
        return 0;
    }
    vector<pair<ll,ll>> vp;
    for(int u=1;u<=n;u++){
        int mnv = -2e9;
        for(int i=0;i<=n;i++){
            if(dp[i][u] < 0) continue; //impossible
            int cur = dp[i][u] - i * gr[u];
            mnv = max(mnv, cur);
        }
        vp.push_back({gr[u], mnv});//AX + B
    }
    sort(vp.begin(), vp.end(), [&](pair<ll,ll> u, pair<ll,ll> v){
        return u.second > v.second;
    });
    ll bg = n+1;
    vector<Seg> st;
    for(auto [a, b] : vp){ //a1 < a2 < ... and b1 > b2 > ... bn
        if(st.size() == 0){
            st.push_back({bg, q, a, b});
        }else{
            auto [l, r, aa, bb] = st.back();
            if(aa >= a){
                //then ax + b always lower
                continue;
            }
            while(st.size()){
                //b <= bb
                auto [l, r, aa, bb] = st.back();
                if(a*l + b >= aa*l + bb) st.pop_back();
                else break;
            }
            if(!st.size()){
                st.push_back({bg, q, a, b});
            }else{
                //find first l, a*l+b >= aa*l + bb
                auto [l, r, aa, bb] = st.back();
                ll lo = l, hi = q+1;
                while(lo != hi){
                    ll mid = lo + (hi - lo)/2;
                    if(a*mid + b >= aa*mid + bb) hi = mid;
                    else lo = mid + 1;
                }
                if(lo <= q){
                    assert(lo-1 <= r);
                    st.back().r = lo-1;
                    st.push_back({lo, q, a, b});
                }
            }
        }
    }
    for(auto [l, r, a, b] : st){
        //ax+b
        ans += (r - l + 1) * b;
        //a1 = al, an = ar, 
        Mint aux = (a*r + a*l);
        aux *= (r - l + 1);
        aux /= 2;
        ans += aux;
    }
    cout << ans << "\n";

}
