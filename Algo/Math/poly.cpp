/*
If you need to use this is any other modulo instead of 998244353
then you need to change some lines
line 100 assumes 31 is a such that 31^(2^23) == 1 mod MOD
line 311 assumes 3^(MOD - 1) == 1 mod MOD


*/
static_assert(MOD == 998244353, 
    "This library assumes MOD = 998244353");
    
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

namespace poly{
    struct Mint{
        int v;
        // static const int MOD = MOD_val;
        Mint(){ v = 0;}
        Mint(ll u){ 
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
    //warning, 31 is a primitive root of 998244353
    //If modulo change, change w1.
    void ntt(vector<Mint> &a, int s) { 
        int n = a.size();
        Mint w1 = 31;
        for(int i = n; i < (1 << 23); i <<= 1) w1 *= w1;
        for (int i=0, j=0; i<n; i++) {
            if (i>j) swap(a[i], a[j]);
            for (int l=n/2; (j^=l) < l; l>>=1);
        }
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
    vector<Mint> multiply(vector<Mint> a, vector<Mint> b) {
        int n = 1;
        while(n < a.size() + b.size() - 1) n *= 2;
        Mint inv  = Mint(1)/n;
        a.resize(n);
        b.resize(n);
        ntt(a,1);
        ntt(b,1);
        for (int i = 0; i < n; i++) a[i] *= b[i];
        ntt(a,-1);
        for (int i = 0; i < n; i++) a[i] *= inv;
        return a;
    }
    struct Poly{
        vector<Mint> vec;
        
        Poly(){}
        Poly(Mint x){vec.resize(1, x);}
        Poly(int size){vec.resize(size);}
        Poly(vector<Mint> &vec){this->vec = vec; normalize();}  
        Poly(const Poly &p){this->vec = p.vec;}
        void normalize(){
            while(vec.size() > 1 && vec.back().v == 0) vec.pop_back();
        }
        void reverse(){
            std::reverse(vec.begin(), vec.end());
        }
        void resize(int n){
            vec.resize(n);
        }
        size_t size(){
            return vec.size();
        }
        Poly mod_xk(int k){
            int x = min((int)this->vec.size(), k);
            Poly ans(x);
            for(int j=0;j<x;j++) ans.vec[j] = vec[j];
            ans.normalize();
            return ans;
        }
        Poly deriv1(){
            Poly ans(*this);
            if(ans.size() == 1) return Poly(Mint(0));
            for(int j=0;j<ans.vec.size()-1;j++) ans.vec[j] = (j+1) * vec[j+1];
            ans.vec.pop_back();
            normalize();
            return ans; 
        }
        //this can be preprocessed (modulo divisions) or is going to take O(n log M)
        Poly integr1(){
            Poly ans(*this);
            ans.vec.push_back(0);
            ans.vec[0] = 0;
            for(int j=1;j<ans.vec.size();j++) ans.vec[j] = vec[j-1] / j;
            normalize();
            return ans;
        }
        Poly shiftright(int n, int x){
            if(vec.size() <= x) return Poly(Mint(0));
            Poly ans(vec.size() - x);
            for(int j=0;j<ans.size();j++){
                ans.vec[j] = vec[j+x];
            }
            ans.resize(n);
            return ans;
        }
        Poly shiftleft(int n, int x){
            Poly ans(x + size());
            for(int j=x;j<ans.size();j++) ans.vec[j] = vec[j-x];
            ans.resize(n);
            return ans;
        }
       
        Poly& operator+= (const Poly &pl){
            vec.resize(max(vec.size(), pl.vec.size()));
            for(int j=0;j<pl.vec.size();j++) vec[j] += pl.vec[j];
            normalize();
            return *this;
        }
        Poly& operator-= (const Poly &pl){
            vec.resize(max(vec.size(), pl.vec.size()));
            for(int j=0;j<pl.vec.size();j++) vec[j] -= pl.vec[j];
            normalize();
            return *this;
        }
        Poly& operator*= (const Poly &pl){
            vec = multiply(vec, pl.vec);
            normalize();
            return *this;
        }
        //returns {0} if deg(A) < deg(B) in A/B
        //Don't divide by 0!!
        Poly& operator/= (Poly pl){
            if(this->size() == 0) return *this = Poly(Mint(0));
            pl.normalize();
            assert(pl.size() != 0 && (pl.size() != 1 || pl.vec[0] != 0)); //PLEASE DON'T DIVIDE BY 0!!!
            int n = this->size() - 1;
            int m = pl.size() - 1;
            if(n < m) return *this = Poly(Mint(0));
            this->reverse();
            pl.reverse();
            pl = pl.inv(n - m + 1);
            *this *= pl;
            this->resize(n - m + 1); //needed for reverse op.
            this->reverse();
            normalize();
            return *this;
        }
        Poly& operator%= (Poly pl){
            Poly d = *this / pl;
            return *this = *this - d * pl;
        }
        Poly operator* (const Poly &t) const {return Poly(*this) *= t;}
        Poly operator/ (const Poly &t) const {return Poly(*this) /= t;}
        Poly operator% (const Poly &t) const {return Poly(*this) %= t;}
        Poly operator+ (const Poly &t) const {return Poly(*this) += t;}
        Poly operator- (const Poly &t) const {return Poly(*this) -= t;}
        Poly inv(int n){
            Poly B;
            for(int i = 1; ; i <<= 1){
                if(i == 1) B.vec = {Mint(1)/vec[0].v};
                else{
                    //Bk = Bk-1 * (2 - ABk-1) mod(x^(2^k))
                    B  = (B * (Poly(Mint(2)) - (this->mod_xk(i) * B)).mod_xk(i)).mod_xk(i);
                }
                if(i >= n) break;
            }
            B.vec.resize(n);
            normalize();
            return B;
        }
        //Here, a0 = 1. If a0 != 1, then ans[0] = ln(a0) (which is not defined in Modulo)
        Poly log(int n){
            Poly p1 = this->inv(n);
            Poly p2 = this->deriv1();
            Poly ans = (p1*p2).mod_xk(n-1).integr1();
            return ans;
        }
        //Here a0 = 0, because e^(P(x) + a0) = e^P(x) * e^a0, again real numbers unless a0=0
        Poly exp(int n){
            Poly Q(Mint(1));
            //Qk = (Qk-1) * (1 + A - log(Qk-1)) 
            for(int i=2;;i <<= 1){
                Q = (Q * (Poly(Mint(1)) + this->mod_xk(i)  - Q.log(i))).mod_xk(i);
                if(i >= n) break;
            }
            Q.vec.resize(n);
            normalize();
            return Q;
        } 
        Poly pow(int n, ll k){
            if(k == 0) return Poly(Mint(1));
            Mint ax;
            int t = -1;
            for(int j=0;j<n;j++){
                if(vec[j] != 0){
                    t = j;
                    ax = vec[j];
                    break;
                }
            }
            if(t == -1) return Poly(Mint(0));
            if(k >= n && t > 0) return Poly(Mint(0));
            if(k*t >= n) return Poly(Mint(0));
            Poly ans(*this);
            ans = ans.shiftright(n, t);
            for(int j=0;j<n;j++){
                ans.vec[j] /= ax;
            }
            ans = ans.log(n);
            for(int j=0;j<n;j++) ans.vec[j] *= Mint(k);
            ans = ans.exp(n);
            Mint ak = ax.pow(k);
            for(int j=0;j<n;j++) ans.vec[j] *= ak;
            ans = ans.shiftleft(n, k*t);
            return ans;
        }
        // returns zero polynomial if root does not exist
        Poly sqrt(int n, int k){
            Mint ax;
            int t = -1;
            for(int j=0;j<n;j++){
                if(vec[j] != 0){
                    t = j;
                    ax = vec[j];
                    break;
                }
            }
            if(t == -1) return Poly(Mint(0));
            Mint ivk = Mint(1)/k;
            // Assumes MOD is prime and 3 is a primitive root (998244353)
            ll x = discrete_log(3, ax.v, MOD);
            if(x % k != 0 || t % k != 0) return Poly(0);
            t /= k;

            Poly ans(*this);
            ans = ans.shiftright(n, k*t);
            for(int j=0;j<n;j++){
                ans.vec[j] /= ax;
            }
            ans = ans.log(n);
            for(int j=0;j<n;j++) ans.vec[j] *= ivk; 
            ans = ans.exp(n);
            Mint ak = Mint(3).pow(x/k);
            for(int j=0;j<n;j++) ans.vec[j] *= ak;
            ans = ans.shiftleft(n, t);
            return ans;
        }
    };
    
}

using namespace poly;