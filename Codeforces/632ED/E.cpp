#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
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
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

// if MOD 786433, w = 5 and change to 1 << 18
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

void multiply(vector<Mint> &a, vector<Mint> &b, int n) {
    ntt(a,n,1);
    ntt(b,n,1);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt(a,n,-1);
    for (int i = 0; i < n; i++) a[i] /= n;
}

void onefy(vector<Mint> &a){
    for(int i=0;i<a.size();i++){
        a[i] = min(a[i].v, 1LL);
    }
}

int chlo(vector<Mint> &a){
    for(int i=a.size()-1;i>=0;i--){
        if(a[i] != 0) return i;
    }
    return 0;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<Mint> a(1 << 20), ans(1 << 20);
    ans[0] = 1;
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        a[aux] = 1;
    }
    while(k){
        if(k & 1){
            auto aux = a;
            int x1 = chlo(a);
            int x2 = chlo(ans);
            int exp = 1 << (32 - __builtin_clz(x1+x2));
            multiply(ans, aux, exp);
            onefy(ans);
        }
        auto aux = a;
        int x1 = chlo(a);
        int exp = 1 << (32 - __builtin_clz(2*x1));
        multiply(a, aux, exp);
        onefy(a);
        k >>= 1;
    }
    for(int i=1;i<=1000000;i++){
        if(ans[i] == 1) cout << i << " ";
    }
    cout << "\n";
}
