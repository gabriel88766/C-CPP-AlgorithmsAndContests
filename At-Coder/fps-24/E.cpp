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

const int N = 305; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}


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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    ll n, m;
    cin >> n >> m;
    vector<Mint> ans(1, 1);
    for(int i=1;i<=m;i++){
        vector<Mint> cm(m+1);
        for(int j=0;j<=i;j++) cm[j] = invfat[j];
        ans = multiply(ans, cm);
        while(ans.size() > n + 1) ans.pop_back();
        // for(auto x : ans) cout << x << " ";
        // if(ans.size() >= n + 1) cout << i << " " << ans.back() * fat[n] << "\n";
    }
    if(ans.size() >= n+1) cout << ans.back() * fat[n] << "\n";
    else cout << "0\n";
}
