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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> l(q), r(q), h(n+1, -1);
    for(int i=0;i<q;i++) cin >> l[i];
    for(int i=0;i<q;i++) cin >> r[i];
    h[n] = 0;
    vector<int> ll(2*n+1, -1), rr(2*n+1, -1), val(2*n+1);
    val[0] = n;
    int cnt = 0;
    for(int i=0;i<q;i++){
        int me = max(l[i], r[i]);
        int u = h[me];
        ll[u] = h[l[i]] = cnt + 1;
        rr[u] = h[r[i]] = cnt + 2;
        val[cnt + 1] = l[i];
        val[cnt + 2] = r[i];
        cnt += 2;
    }
    vector<int> aux;
    function <void(int)> dfs = [&](int u){
        if(ll[u] != -1){
            dfs(ll[u]);
            dfs(rr[u]);
        }else{
            aux.push_back(val[u]);
        }
    };
    dfs(0);
    priority_queue<int> pq;
    pq.push(aux[0]);
    pq.push(aux.back());
    for(int i=1;i<aux.size();i++){
        pq.push(max(aux[i], aux[i-1]));
    }
    int cur = 0;
    Mint ans = 1;
    for(int i=n;i>=1;i--){
        while(pq.size() && pq.top() >= i){
            cur++;
            pq.pop();
        }
        if(h[i] == -1){
            ans *= cur;
            cur++;
        }
    }
    cout << ans << "\n";
}
