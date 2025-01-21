struct Mint{
    const long long MOD = 1'000'000'007;
    long long v;
    Mint(){ v = 0;}
    Mint(long long u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    Mint pow(long long u){
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
    Mint operator= (Mint u) {this->v = u.v; return *this;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
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

struct Comb{
    vector<Mint> fat, invfat;
    int N;
    Comb(int maxn){ //MOD must be prime
        N = maxn;
        for(int i=0;i<N;i++){
            fat.push_back(Mint(1));
            invfat.push_back(Mint(1));
        }
        for(int i=1;i<N;i++){
            fat[i] = fat[i-1]*i;
        }
        invfat[N-1] = 1/fat[N-1];
        for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
    }
    Mint nCr(int a, int b){
        return fat[a]*invfat[a-b]*invfat[b];
    }
};