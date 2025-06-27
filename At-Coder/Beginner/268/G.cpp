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

vector<string> v;
const int N = 5e5+3;
//Using Mint

Mint ans[N];
Mint inv = 1/Mint(2);
void solve(int l, int r, const int c){
    if(l == r) return;
    if(c == v[l].size()){
        for(int j=l+1;j<=r;j++) ans[j] += 1;
        l++;
        if(l == r) return;
    }
    char lc = v[l][c], cl = 0;
    vector<int> ql;
    for(int j=l;j<=r;j++){
        if(v[j][c] == lc) cl++;
        else{
            ql.push_back(cl);
            cl = 1;
            lc = v[j][c];
        }
    }
    ql.push_back(cl);
    if(ql.size() == 1) {
        solve(l, r, c+1);
        return;
    }
    Mint aux = 0;
    for(int i=0;i<ql.size();i++){
        aux += ql[i] * inv;
    }
    for(int i=0;i<ql.size();i++){
        aux -= ql[i] * inv;
        for(int j=l;j<l + ql[i]; j++){
            ans[j] += aux;
        }
        solve(l, l + ql[i] - 1, c + 1);
        l += ql[i];
        aux += ql[i] * inv;
    }
    assert(l == r + 1);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    v.resize(n+1);
    vector<int> ord(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){
        return v[a] < v[b];
    });
    vector<int> invord(n+1);
    for(int i=1;i<=n;i++) invord[ord[i]] = i;
    sort(v.begin(), v.end());
    solve(1, n, 0);


    for(int i=1;i<=n;i++) cout << ans[invord[i]]+1 << "\n";
}
