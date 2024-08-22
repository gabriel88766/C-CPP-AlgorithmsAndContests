#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ull MOD = 9223372037190320129ULL;
int n;
struct Mint{
    ull v;
    Mint(){ v = 0;}
    Mint(ull u){ v = u % MOD;}

    Mint pow(ull u){
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
    Mint operator*= (Mint u){ v = ((__int128)u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v >= MOD-u.v ? v-(MOD-u.v) : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v < u.v ? v+(MOD-u.v) : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

// if MOD 786433, w = 5 and change to 1 << 18
void ntt(vector<Mint> &a, int n, int s) { //1927755973360576764^(2^26) == 1 (mod 9223372037190320129), so, for example, if n = 2^16, w1 = 1927755973360576764^(2^10)
    Mint w1 = 1927755973360576764ULL;
    for(int i = n; i < (1 << 26); i <<= 1) w1 *= w1;
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

const __int128 rmod = (__int128)1 << 64; //rmod <= 2^64
void multiply(vector<ull> &a, vector<ull> &b) {
    // N * amax^2 <= MOD - 1 
    ull ax = sqrt((MOD-1)/n);
    while(ax*ax*n >= MOD) ax--;
    __int128 aux = 1;
    int p;
    vector<ull> pot = {1}; //1 2965820 8796093022528, for n = 1 << 20
    for(int i=1;;i++){
        aux *= ax;
        if(aux >= rmod){
             p = i;
             break;
        }
    }
    for(int i=1;i<=2*p-2;i++){
        pot.push_back( ((__int128)pot.back() * ax) % rmod);
    }
    vector<vector<Mint>> pa(p, vector<Mint>(n)), pb(p, vector<Mint>(n));
    
    for(int j=0;j<p;j++){
        for(int i=0;i<n;i++){
            pa[j][i] = (a[i] / pot[j]) % ax;
            pb[j][i] = (b[i] / pot[j]) % ax;
        }
        ntt(pa[j], n, 1);
        ntt(pb[j], n, 1);
    }
    vector<ull> res(n, 0);
    Mint invn = Mint(1)/n;
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            vector<Mint> rs(n);
            for(int k=0;k<n;k++){
                rs[k] = pa[i][k] * pb[j][k];   
            }
            ntt(rs, n, -1);
            for(int k=0;k<n;k++){
                rs[k] *= invn;
                res[k] = ((__int128)rs[k].v * pot[i+j] + res[k]) % rmod;
            }
        }
    }
    a = res;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int a, b;
    cin >> a >> b;
    int x = a + b - 1;
    n = 1;
    while(n <= x) n *= 2;
    vector<ull> v1(n), v2(n);
    for(int i=0;i<a;i++) cin >> v1[i];
    for(int i=0;i<b;i++) cin >> v2[i];
    multiply(v1, v2);
    for(int i=0;i<a+b-1;i++) cout << v1[i] << " ";
    cout << "\n";
}
