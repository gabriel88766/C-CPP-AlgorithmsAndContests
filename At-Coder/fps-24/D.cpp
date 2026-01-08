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

void ntt(vector<Mint> &a, int n, int s) { //31^(2^23) == 1 (mod 998244353), so, for example, if n = 2^16, w1 = 31^(2^7)
    Mint w1 = 31;
    for(int i = n; i < (1 << 23); i <<= 1) w1 *= w1;
    for (int i=0, j=0; i<n; i++) {
        if (i>j) swap(a[i], a[j]);
        for (int l=n/2; (j^=l) < l; l>>=1);
    }
    //w1^n = 1
    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        Mint wn = w1.pow( n + s*(n/M)); 
        for(int j = 0; j < n; j += M) {
            Mint w = 1;
            for(int l = j; l < K + j; ++l){
                Mint t = w*a[l + K];
                a[l + K] = a[l] - t;
                a[l] = a[l] + t;
                w *= wn;
            }
        }
    }
}

vector<Mint> multiply(vector<Mint> a, vector<Mint> b) {
    int n = 1;
    while(n < a.size() + b.size() - 1) n *= 2;
    a.resize(n);
    b.resize(n);
    ntt(a,n,1);
    ntt(b,n,1);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt(a,n,-1);
    Mint inv  = Mint(1)/n;
    for (int i = 0; i < n; i++) a[i] *= inv;
    while(a.back() == 0) a.pop_back();
    return a;
}

vector<vector<Mint>> mul(vector<vector<Mint>> ax, vector<vector<Mint>> bx){
    int n = 1;
    int mx = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            mx = max(mx, (int)ax[i].size() + (int)bx[j].size());
        }
    }
    while(n < mx) n *= 2;
    for(int j=0;j<4;j++){
        ax[j].resize(n);
        bx[j].resize(n);
        ntt(ax[j], n, 1);
        ntt(bx[j], n, 1);
    }
    vector<vector<Mint>> res(4);
    for(int j=0;j<4;j++) res[j].resize(n);
    for(int i=0;i<n;i++){
        res[0][i] = ax[0][i] * bx[0][i] + ax[1][i] * bx[2][i];
        res[1][i] = ax[0][i] * bx[1][i] + ax[1][i] * bx[3][i];
        res[2][i] = ax[2][i] * bx[0][i] + ax[3][i] * bx[2][i];
        res[3][i] = ax[2][i] * bx[1][i] + ax[3][i] * bx[3][i];
    }
    Mint inv  = Mint(1)/n;
    for(int j=0;j<4;j++){
        ntt(res[j], n, -1);
        for(int i=0;i<n;i++){
            res[j][i] *= inv;
        }
        while(res[j].size() > 1 && res[j].back() == 0) res[j].pop_back();
    }
    return res;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    cin >> n >> m;
    vector<vector<Mint>> aux = {{0, 1}, {1}, {1}, {0}};
    vector<vector<Mint>> ans = {{1}, {0}, {0}, {1}};
    m++;
    int cnt = 0;
    while(m){
        if(m & 1){
            ans = mul(ans, aux);
        }
        m >>= 1;
        if(m){
            aux = mul(aux, aux);
            cnt++;
        }
    }
    Mint ansn = 0;
    for(int j=0;j<4;j++){
        if(n < ans[j].size()) ansn += ans[j][n];
    }
    for(int i=1;i<=n;i++) ansn *= i;
    cout << ansn << "\n";
}
