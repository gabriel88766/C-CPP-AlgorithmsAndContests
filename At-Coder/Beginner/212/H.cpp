#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
ll binpow(ll a, ll b, ll m = MOD){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

struct Mint{
    ll v;
    Mint(){ v = 0;}
    Mint(ll u){ v = u%MOD;}
    Mint operator* (Mint u){ return Mint((v*u.v) % MOD);}
    Mint operator+ (Mint u){ return Mint((v+u.v >= MOD ? v+u.v-MOD : v+u.v));}
    Mint operator- (Mint u){ return Mint((v-u.v >= 0 ? v-u.v : v-u.v+MOD));}
    Mint operator/ (ll u){ return Mint((v*binpow(u, MOD-2)));}
};

//change to ntt
void ntt(vector<Mint> &a, int n, int s) { //31^(2^23) == 1, so, for example, if n = 2^16, w1 = 31^(2^7)
    ll w1 = 31;
    for(int i = n; i < (1 << 23); i <<= 1) w1 = (w1*w1)%MOD;
    for (int i=0, j=0; i<n; i++) {
        if (i>j) swap(a[i], a[j]);
        for (int l=n/2; (j^=l) < l; l>>=1);
    }
    //w1^n = 1
    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        Mint wn(binpow(w1, n + s*(n/M))); 
        for(int j = 0; j < n; j += M) {
            Mint w(1LL);
            for(int l = j; l < K + j; ++l){
                Mint t = w*a[l + K];
                a[l + K] = a[l] - t;
                a[l] = a[l] + t;
                w = wn*w;
            }
        }
    }
}

void multiply(vector<Mint> &a, vector<Mint> &b) {
    ntt(a,n,1);
    ntt(b,n,1);
    for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
    ntt(a,n,-1);
    for (int i = 0; i < n; i++) a[i] = a[i]/n;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    /*int m, k;
    vector<int> v(k+1);
    cin >> m >> k;
    for(int i=1;i<=k;i++) cin >> v[i];
    n = 1 << 16;
    vector<ll> a(n,0);
    for(int i=1;i<=k;i++){
        a[v[i]] = 1;
    }

    ll ans = 0;
    vector<ll> ansv(n,0);
    ansv[0] = 1;
    while(m){
        if(m & 1){
            multiply(ansv, a);
        }
        m >>= 1;
        multiply(a,a);
    }
    for(int i=1;i<n;i++) ans = (ans + ansv[i]) % MOD;
    cout << ans;*/
    n = 1 << 16;
    vector<Mint> a(n, 0);
    vector<Mint> b(n, 0);
    a[1].v = 1, a[2].v = 3, a[3].v = 2;
    b[1].v = 1, b[2].v = 3, b[3].v = 2;
    for(int i=0;i<10;i++) cout << a[i].v << " ";
    cout << "\n";
    multiply(a,b);
    for(int i=0;i<10;i++) cout << a[i].v << " ";
    cout << "\n";
}
