#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1'234'567'890; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;



struct Complex {
    long double x, y;
    Complex() : x(0), y(0) {}
    Complex(long double a, long double b=0) : x(a), y(b) {}
    Complex operator/=(long double k) { x/=k; y/=k; return (*this); }
    Complex operator*(Complex a) const { return Complex(x*a.x - y*a.y, x*a.y + y*a.x); }
    Complex operator+(Complex a) const { return Complex(x+a.x, y+a.y); }
    Complex operator-(Complex a) const { return Complex(x-a.x, y-a.y); }
};

void fft(vector<Complex> &a, int n, int s) {
    for (int i=0, j=0; i<n; i++) {
        if (i>j) swap(a[i], a[j]);
        for (int l=n/2; (j^=l) < l; l>>=1);
    }
    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        Complex wn = Complex(cosl(s*2*PI/M), sinl(s*2*PI/M));
        for(int j = 0; j < n; j += M) {
            Complex w = Complex(1, 0);
            for(int l = j; l < K + j; ++l){
                Complex t = w*a[l + K];
                a[l + K] = a[l] - t;
                a[l] = a[l] + t;
                w = wn*w;
            }
        }
    }
}

void multfft(vector<Complex> &a, vector<Complex> &b, int n) {
    fft(a,n,1);
    fft(b,n,1);
    for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
    fft(a,n,-1);
    for (int i = 0; i < n; i++) a[i] /= n;
}

struct BigNum{
    static const int LEN_EACH = 4; //numbers up to N digits, each coeficient up to (N²/k²)*10^k value
    static const int MAX_INT = 10000;
    int s = 1;
    vector<ll> cfs;
    BigNum(){}
    BigNum(string num){
        reverse(num.begin(), num.end());
        if(num.back() == '-'){
            s = -1;
            num.pop_back();
        }
        int sz = (num.size()+LEN_EACH-1)/LEN_EACH;
        cfs.resize(sz);
        for(int i=0;i<num.size();i+=LEN_EACH){
            string s = num.substr(i, LEN_EACH);
            reverse(s.begin(), s.end());
            int cur = 0;
            for(auto x : s){
                cur *= 10;
                cur += x - '0';
            }
            cfs[i/LEN_EACH] = cur;
        }
    }
    void print(){
        if(s == -1) cout << "-";
        if(cfs.size()){
            for(int i=cfs.size()-1;i>=0;i--){
                if(i == cfs.size() - 1) cout << cfs[i];
                else cout << setfill('0') << setw(LEN_EACH) << cfs[i];
            }
            cout << "\n";
        }
    }
    //compare modulo
    bool operator< (BigNum &b){
        if(cfs.size() != b.cfs.size()){
            return cfs.size() < b.cfs.size();
        }else{
            for(int i=cfs.size()-1;i>=0;i--){
                if(cfs[i] != b.cfs[i]) return cfs[i] < b.cfs[i];
            }
            return false;
        }
    }
    bool operator== (BigNum &b){
        if(cfs.size() != b.cfs.size()) return false;
        else{
            for(int i=cfs.size()-1;i>=0;i--){
                if(cfs[i] != b.cfs[i]) return false;
            }
            return true;
        }
    }
    //dont call this.
    //call add instead
    BigNum sub(BigNum &b){
        BigNum &a = *this;
        if(a == b){
            BigNum ans("0");
            return ans;
        }else{
            BigNum ans;
            int borrow = 0;
            for(int i=0;i<min(a.cfs.size(), b.cfs.size());i++){
                int now = a.cfs[i] - b.cfs[i] - borrow;
                if(0 > now){
                    borrow = 1;
                    now += MAX_INT;
                }else borrow = 0;
                ans.cfs.push_back(now);
            }
            for(int i=min(a.cfs.size(), b.cfs.size()); i<a.cfs.size();i++){
                int now = a.cfs[i] - borrow;
                if(0 > now){
                    borrow = 1;
                    now += MAX_INT;
                }else borrow = 0;
                ans.cfs.push_back(now);
            }
            while(ans.cfs.back() == 0) ans.cfs.pop_back();
            ans.s = a.s;
            return ans;
        }
    }
    BigNum add(BigNum b){
        BigNum a = *this;
        if(a < b) swap(a, b); //a>=b
        BigNum ans;
        if(a.s == b.s){//OK
            int c = 0;
            for(int i=0;i<min(a.cfs.size(), b.cfs.size());i++){
                int now = a.cfs[i] + b.cfs[i] + c;
                if(now >= MAX_INT){
                    c = 1;
                    now -= MAX_INT;
                }else c = 0;
                ans.cfs.push_back(now);
            }
            for(int i=min(a.cfs.size(), b.cfs.size()); i<a.cfs.size();i++){
                int now = a.cfs[i] + c;
                if(now >= MAX_INT){
                    c = 1;
                    now -= MAX_INT;
                }else c = 0;
                ans.cfs.push_back(now);
            }
            if(c) ans.cfs.push_back(c);
            ans.s = a.s;
        }else ans = a.sub(b);
        return ans; 
    }
    BigNum multiply(BigNum &b){
        BigNum ans;
        BigNum &a = *this;
        ans.s = s * b.s;
        int sz = b.cfs.size() + a.cfs.size();
        int n = 1;
        while(n < sz) n*=2;
        vector<Complex> c(n), d(n);
        for(int i=0;i<a.cfs.size();i++){
            c[i].x = a.cfs[i];
        }
        for(int i=0;i<b.cfs.size();i++){
            d[i].x = b.cfs[i];
        }
        multfft(c, d, n);
        ll carry = 0;
        for(int i=0;i<n;i++){
            ll now = round(c[i].x);
            now += carry;
            ans.cfs.push_back(now % MAX_INT);
            carry = now / MAX_INT;
        }
        while(carry){
            ans.cfs.push_back(carry % MAX_INT);
            carry /= MAX_INT;
        }
        while(ans.cfs.back() == 0) ans.cfs.pop_back();
        if(ans.cfs.size() == 0){
            ans.cfs.push_back(0);
            ans.s = 1;
        }
        return ans;
    }
    BigNum pow(int exp){
        BigNum ans("1");
        BigNum aux = *this;
        while(exp){
            if(exp & 1) ans = ans.multiply(aux);
            aux = aux.multiply(aux);
            exp >>= 1;
        }
        return ans;
    }
};



const int N = 101;
char p[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
int lf[N];
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
                if(lf[j] == 0) lf[j] = i;
            }
            primes.push_back(i);
        }
    }
}

//sum [gcd(cte, i) == val] from i = 1 to n;
ll sumgcd(ll val, ll cte, ll n){
    if(val != 1){
        return sumgcd(1, cte/val, n/val);
    }
    vector<int> v;
    ll aux = cte;
    while(aux != 1){
        if((!v.size()) || (v.back() != lf[aux])) v.push_back(lf[aux]);
        aux /= lf[aux];
    }
    int sz = v.size();
    ll ans = 0;
    for(int i=0;i<(1<<sz);i++){
        ll f = 1;
        for(int k=0;k<sz;k++){
            if(i & (1 << k)){
                f *= v[k];
            }
        }
        if(__builtin_popcount(i) % 2) ans -= n/f;
        else ans += n/f;
    }
    return ans;
}

vector<ll> multpoly(vector<ll> &poly1, vector<ll> &poly2){
    vector<ll> ans(poly1.size(), 0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            ans[i^j] += poly1[i] * poly2[j];
            ans[i^j] %= MOD;
        }
    }
    return ans;
}

vector<ll> exppoly(vector<ll> &poly, ll n){
    vector<ll> ans(64, 0);
    ans[0] = 1;
    while(n){
        if(n & 1) ans = multpoly(ans, poly);
        poly = multpoly(poly, poly);
        n >>= 1;
    }
    return ans;
}

bool aux_find(ll p, ll q, long double x, int s){
    if(s == 1) return (q*x > p);
    else return (q*x < p);
}

bool aux_find2(__int128 p, __int128 q, long double x, int s){
    //for x = sqrt(n) for some n integer.
    ll n = x*x+0.001;
    assert(p <= 1e18); //no overflow
    __int128 ans = (p*p)/(q*q);
    if(s == 1) return ans < n;
    else return ans >= n;
}
//find the p/q <= x with limited q max.
//experimental!
//if s == 1, find lower, if s == -1, find higher
//this version doesn't work for irrational numbers, change aux_find;
//example for sqrt is aux_find2
ll cnt = 0;
pair<ll, ll> findpq(long double x, int s = 1, ll den = 1'000'000'000'000LL){
    ll pl = 0;
    ll ql = 1;
    ll pr = 1;
    ll qr = 0;
    if(s == -1){swap(pl, pr); swap(ql, qr);}
    ll pm = 0, qm = 0;
    while(true){
        if(ql + qr > den) break;
        ll c = 0;
        //den * jp <= 1e18
        for(ll jp = 1'000'000; jp >= 1; jp >>= 1){
            while(ql+qr*(c+jp) <= den && aux_find2(pl + (c+jp)*pr, ql + (c+jp)*qr, x, s)) {c += jp; cnt++;}
        }
        pm = pl + c*pr;
        qm = ql + c*qr;
        if(c == 0){
            //makes the algorithm linear sometimes.
            //check the best next (pr + c*pl)/(qr + c*ql) > numf/denf 
            for(ll jp = 1'000'000; jp >= 1; jp >>= 1){
                while(qr+ql*(c+jp) <= den && aux_find2(pr + (c+jp)*pl, qr + (c+jp)*ql, x, -s)) {c += jp; cnt++;}
            }
            qr += c*ql;
            pr += c*pl;
        }else{
            qr += qm;
            pr += pm;
            ql = qm;
            pl = pm;
        }
    }
    return {pm, qm};
}

// true if p1/q1 + p2/q2 < sqrt(n)
bool spcmp(ll p1, ll q1, ll p2, ll q2, ll n){
    BigNum num1(to_string(p1));
    BigNum num2(to_string(p2));
    BigNum aux(to_string(q2));
    num1 = num1.multiply(aux);
    aux = BigNum(to_string(q1));
    num2 = num2.multiply(aux);
    num1 = num1.add(num2);
    BigNum den(to_string(q1));
    aux = BigNum(to_string(q2));
    den = den.multiply(aux);
    den = den.multiply(den);
    num1 = num1.multiply(num1);
    aux = BigNum(to_string(4*n));
    den = den.multiply(aux);
    return num1 < den;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test inpu
    ll ans = 0;
    for(int i=2;i<=100'000;i++){
        ll x = sqrt(i);
        while(x*x > i) x--;
        while(x*x < i) x++;
        if(x*x == i) continue;
        auto [p1, q1] = findpq(sqrtl(i), 1);
        auto [p2, q2] = findpq(sqrtl(i), -1);
        if(spcmp(p1, q1, p2, q2, i)) ans += q2;
        else ans += q1;

        //ans += max(q1, q2);
    }
    cout << ans << "\n";
    cout << cnt << "\n";
}   