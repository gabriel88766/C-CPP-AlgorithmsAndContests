#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 786433; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
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

//change to ntt
void ntt(vector<Mint> &a, int n, int s) { 
    Mint w1 = 5;
    for(int i = n; i < (1 << 18); i <<= 1) w1 *= w1;
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

int pos[786433];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    n = 1 << 18;
    vector<Mint> a(n), b(n), c(n);
    int m;
    cin >> m;
    for(int i=0;i<=m;i++){
        if(i%3 == 0) cin >> a[i/3].v;
        else if(i%3 == 1) cin >> b[i/3].v;
        else cin >> c[i/3].v;
    }
    ll v0 = a[0].v;
    ntt(a, n, 1);
    ntt(b, n, 1);
    ntt(c, n, 1);
    Mint w = 1;
    for(int i=0;i<n;i++){
        pos[w.v] = i;
        w *= 5;
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        ll k;
        cin >> k;
        if(k == 0){
            cout << v0 << "\n";
            continue;
        }
        Mint cubic = k*k*k;
        cout << a[pos[cubic.v]] + b[pos[cubic.v]]*k + c[pos[cubic.v]]*k*k << "\n";
    }
}