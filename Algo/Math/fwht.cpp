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

//Worth to know;
//Matrix to transform for Xor is (1,1) (1,-1), for OR (1,0) (1,1) and for AND (0,1) (1,1)
//Remember n = 2^x
// FWHT(A) + FWHT(B) + .... = FWHT(A + B + C + D + ...) for product it also holds(Linear Algebra)
//FAST WALSH HADAMARD TRANSFORM
void fwht(vector<Mint> &a, int lo, int hi) { 
    if(lo == (hi-1)) return;
    //w1^n = 1
    int mid = lo + (hi-lo)/2;
    fwht(a, lo, mid);
    fwht(a, mid, hi);
    for(int i = 0; lo+i < mid; i++){
        Mint x = a[lo+i];
        Mint y = a[mid+i];
        a[lo+i] = x + y;
        a[mid+i] = x - y; 
    } 
}

void multiply(vector<Mint> &a, vector<Mint> &b) { //just one example of task, sometimes you don't want multiply!
    fwht(a,0,n);
    fwht(b,0,n);
    for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
    fwht(a,0,n);
    for (int i = 0; i < n; i++) a[i] = a[i]/n;
}
