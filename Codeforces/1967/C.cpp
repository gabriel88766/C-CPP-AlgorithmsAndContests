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


void query(int b){
    int x = b;
    b--;
    for(int i = b; i > (x ^ (x & -x)) ; i -= i & -i){
        cout << i << " ";
    }
}

const int N = 2e5+3;
//map<int, Mint> mp[N];

vector<Mint> mp[N];


vector<Mint> T(vector<Mint> p1){
    int n = p1.size();
    vector<Mint> ans(n);
    for(int i=1;i<n;i++){
        for(int j=0;j<mp[i].size();j++){
            ans[i] += mp[i][j] * p1[i-j];
        }
    }
    return ans;
}

void auxT(int n){
    for(int i=n;i>=1;i--){
        vector<Mint> nv(i & -i);
        for(int j=0;j<nv.size();j++){
            for(int k=0;k<mp[i-j].size();k++){
                nv[j+k] += mp[i][j] * mp[i-j][k];
            }
        }
        mp[i] = nv;
    }
}

void auxT1(int n){
    for(int i=n;i>=1;i--){
        int b = i - 1;
        for(int x = b; x > (i ^(i & -i)); x -= (x & -x)){
            mp[i][i-x] = -1;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<Mint> v(n+1);
        for(int i=1;i<=n;i++){
            ll aux;
            cin >> aux;
            v[i] = aux;
            mp[i].resize(i & -i);
            mp[i][0] = 1;
        }
        auxT1(n);
        while(k){
            if(k & 1){
                v = T(v);
            }
            k >>= 1;
            auxT(n);
        }
        for(int i=1;i<=n;i++) cout << v[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++) mp[i].clear();
    }
}