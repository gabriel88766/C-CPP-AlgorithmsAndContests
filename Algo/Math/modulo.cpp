ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

//when 4e18 > m > 1e9
ll binmul(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 0;
    while(b){
        if(b & 1){
            ans += a;
            if(ans > m) ans -= m;
        } 
        a += a;
        if(a > m) a -= m;
        b >>= 1;
    }
    return ans;
}
//for m prime, b^(m-1) == 1 (mod m) => a/b = a*1/b == a*b^(m-2) (mod m)
//if m is not prime, change m-2 to phi(m)-1 (case m = 1e9+6, 5e8+1)
//if phi(m) is determined at exec time, add a new param.
//remember a^k == a^(k mod(m-1)) mod m
ll divmod(ll a, ll b, ll m){
    return (a * binpow(b, m-2, m)) % m;
}

//inv, if m = prime, and division, 4/3 = 4 * inv 3 mod p
long long int x = 600,y = 2,p = 998244353;
long long inv = binpow(y, p-2, p);
long long div = (x * inv) % p;
//cout << inv << " " << div; //must output 300

//Mint
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