//version 1
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