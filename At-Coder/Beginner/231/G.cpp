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
    Mint(int u){ 
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

vector<Mint> multiply2(vector<Mint> a, vector<Mint> b) {
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

const int N = 1005;


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


Mint dp[N][N];



Mint sum[N];


Mint solve(ll n, ll k){
    n %= MOD;
    for(int i=0;i<=k+1;i++){
        if(i == 0) sum[i] = dp[k][i];
        else sum[i] = dp[k][i] / Mint(k).pow(i); 
    }
    if(n <= k+1) return sum[n];
    else{
        //https://en.wikipedia.org/wiki/Lagrange_polynomial
        // ym = sum[m], k+1 points
        Mint ans = 0;
        Mint prod = 1;
        for(int i=1;i<=k+1;i++) prod *= (n - i);
        for(int i=1;i<=k+1;i++){
            if((k+1-i) % 2) ans -= sum[i] * prod / (fat[k+1-i]*fat[i-1] * (n - i));
            else ans += sum[i] * prod / (fat[k+1-i]*fat[i-1] * (n - i));
        }
        return ans;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    init();
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
         cin >> v[i];
         v[i] %= MOD;
    }


    for(int i=0;i<=n+1;i++){
        dp[1][i] = i + v[1];
    }
    int cnt = 0;
    for(int i=2;i<=n;i++){
        vector<Mint> vks(n+2);
        vector<Mint> dpx(n+2);
        for(int j=0;j<=n+1;j++){
            dpx[j] = dp[i-1][j] * invfat[j];
            vks[j] = Mint(j + v[i]) * invfat[j];   
        }
        auto sx = multiply2(vks, dpx);
        for(int j=0;j<=n+1;j++) dp[i][j] = sx[j]  * fat[j];
    }



    cout << solve(k, n) << "\n";
}
