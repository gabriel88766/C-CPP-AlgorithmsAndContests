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

//find a^x == b mod (m) if exists;
//x = np-q, a^x == b mod(m) thus a^np == a^q * b (mod m)
// -1 if not found
ll discrete_log(ll a, ll b, ll m){
    a %= m; b %= m;
    if(a == 0 && b == 1) return 0; //if 0^0 == 1
    if(a == 0 && b == 0 && m == 1) return 0; //if 0^0 == 1
    if(a == 0 && b == 0) return 1;
    if(a == 0) return -1;   
    ll g, add = 0, k = 1;
    while((g = gcd(a, m)) > 1){
        if(b == k) return add;
        if(b % g) return -1;
        b /= g;
        m /= g;
        k = (k * (a / g)) % m;
        add++;
    }
    if(b == k) return add;
    //ka^(x-1) == b (mod m) => k*a^(np) == a^q * b (mod m); return np-q+1, p>=1 && q < n
    ll n = ceil(sqrt(m)) + 0.01; //n*n > m
    ll aux = binpow(a, n, m);
    map<ll, ll> mp; //change to unordered if you want "O(1)"
    ll bx = b;
    mp[bx] = 0;
    for(int i=1;i<n;i++){
        bx = (bx * a) % m;
        mp[bx] = i;
    }
    ll ax = k;
    for(ll i=1;i<=n;i++){
        ax = (ax * aux) % m;
        if(mp.count(ax)){
            return n*i - mp[ax] + add;
        }
    }
    return -1;
}

//inv, if m = prime, and division, 4/3 = 4 * inv 3 mod p
long long int x = 600,y = 2,p = 998244353;
long long inv = binpow(y, p-2, p);
long long div = (x * inv) % p;
//cout << inv << " " << div; //must output 300

//Mint
// template <int MOD_val=998244353>
struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        if(u < 0) return (Mint(1)/v).pow(-u);
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

//Montgomery
//How to use?
//example multiplication and retrieve result
// Montgomery ms(MOD);
// u32 x1_mt = ms.init(53);
// u32 x2_mt = ms.init(37);
// u32 res_mt = ms.mult(x1_mt, x2_mt);
// u32 res = ms.reduce(res_mt);
using u32 = uint32_t; 
using u64 = uint64_t;
using i32 = int32_t;
//this is the first step, montgomery MOD
struct Montgomery{
    u32 mod;
    u32 inv; ///inv * mod == 1 (mod 2^32)
    u32 r;
    u32 r2;
    Montgomery(u32 n) : mod(n), inv(1) {
        for (int i = 0; i < 5; i++) 
            inv *= 2 - n * inv;
        r = (u64(1) << 32) % mod; 
        r2 = u64(r) * r % mod;
    }
    u32 init(u32 x){
        return mult(x, r2);
    }
    u32 reduce(u64 num){
        u32 q = num * inv;
        i32 a = (num - u64(q) * mod) >> 32;
        if(a < 0) a += mod;
        return a;
    }
    u32 mult(u32 a, u32 b){
        return reduce(u64(a) * b);
    }
    u32 pow(u32 a, u32 b){
        u32 ans = init(1);
        while(b){
            if(b & 1) ans = mult(ans, a);
            a = mult(a, a);
            b >>= 1;
        }
        return ans;
    }
};
