//version 3
struct Mint{
    int v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
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
    Mint operator*= (Mint u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

/*
*   NTT, number theoretical transform (MOD default 998244353) based on FFT
*   also needs the definition of Mint (struct to modular arithmetics)
*   as input a vector<Mint> a(n), int n, int s;
*   
*   a(n) is the array in x = 0, 1, 2 ..., n-1.
*   n is a power of 2 <= 2^23
*   s is the direction, 1 is forward, anything else backwads.   
*
*   MOD must be 2^x * m + 1 and 2^x >= n.
*   you must replace 31 by y^m and 128805723 by y^{-m} being y some primitive root.
*   if MOD 786433, w = 5 and change to 1 << 18
*   use MOD 9223372037190320129 and w = 1927755973360576764 for more precision (2^26 * m + 1);
*   see also multiply
*/

void ntt(vector<Mint> &a, int n, int s){ //31^(2^23) == 1 (mod 998244353), so, for example, if n = 2^16, w1 = 31^(2^7)
    Mint w = s == 1 ? 31 : 128805723;
    for(int i = n; i < (1 << 23); i <<= 1) w *= w;
    int hf = n/2;
    vector<Mint> aux(a.size());
    for(int j = 2; j <= n; j *= 2){
        Mint cw = w.pow(n/j);
        int jmp = n/j;
        aux.swap(a);
        //now transform {0, jmp, 2*jmp, ...} {1, jmp + 1, ...} ... combining results with jmp = 2jmp 
        Mint wx = 1;
        for(int k = 0; k < j/2; k++){
            for(int i = 0; i < jmp; i++){ //access is more contiguous using i as inner loop.
                Mint t1 = aux[i + 2 * k * jmp];
                Mint t2 = aux[i + (2 * k + 1) * jmp];
                a[i + k * jmp] = t1 + wx * t2;
                a[i + k * jmp + hf] = t1 - wx * t2;
            }
            wx = wx * cw;
        }
    }
}

/*
*   Convolutions, here is why NTT exists.
*   calculate c[k] sum of ai*bj such that i + j = k.
*   multiply 1 rely on already expanded arrays, multiply 2 expand and shrink the array. 
*   multiply 1 also writes the answer in array a.
*/

void multiply(vector<Mint> &a, vector<Mint> &b) {
    int n = a.size();
    ntt(a,n,1);
    ntt(b,n,1);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt(a,n,-1);
    Mint inv  = Mint(1)/n;
    for (int i = 0; i < n; i++) a[i] *= inv;
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
    while(a.size() > 1 && a.back() == 0) a.pop_back();
    return a;
}