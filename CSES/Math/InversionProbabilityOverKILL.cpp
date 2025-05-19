//The rounding method made me make this beast
//Enjoy...
//Unfortunately lcm(1, 2, 3, ..., 100) can't be hold by int128, so I didn't try that way
//Custom int256 can work, anyway.
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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
    int mod(int num){
        int md = 0;
        for(int i=cfs.size()-1;i>=0;i--){
            md *= 10000;
            md += cfs[i];
            md %= num;
        }
        return md;
    }
    void div(int num){
        int carry = 0;
        for(int i=cfs.size()-1;i>=0;i--){
            int ncarry = ((cfs[i] + carry) % num) * 10000;
            cfs[i] = (cfs[i] + carry) / num;
            carry = ncarry;
        }
        while(cfs.size() > 1 && cfs.back() == 0) cfs.pop_back();
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
    bool operator<= (BigNum &b){
        return (*this < b) || (*this == b);
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


//Yeah, mistakenly swap numerator and denominator.
//refactoring later...
struct Frac{
    BigNum d, n;
    void reduce(){
        for(auto num : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}){
            while(n.mod(num) == 0 && d.mod(num) == 0){
                n.div(num);
                d.div(num);
            }
        }
    }
    friend Frac operator+ (Frac a, Frac &b){ return a += b;}
    Frac operator+= ( Frac &u) {
        d = d.multiply(u.n).add(n.multiply(u.d));
        n = n.multiply(u.n);
        this->reduce();
        return *this;
    }
    friend Frac operator* (Frac a, Frac  &b){ return a *= b;}
    Frac operator*= ( Frac &u){
        d = d.multiply(u.d);
        n = n.multiply(u.n);
        this->reduce();
        return *this;
    }
    
    Frac(int a, int b){
        d = BigNum(to_string(a));
        n = BigNum(to_string(b));
    }
    Frac(){
        d = BigNum("0");
        n = BigNum("1");
    }
};


const int N = 105;
int v[N];
Frac aux[N]; //count of numbers greater than or equal to i
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    Frac ans;
    for(int i=1;i<=n;i++){
        Frac x;
        for(int j=1;j<=v[i];j++){
            x += aux[j+1];
        }
        Frac p(1, v[i]);
        x *= p;
        ans += x; 
        for(int j=1;j<=v[i];j++){
            Frac p(v[i] - j + 1, v[i]);
            aux[j] += p;
        }
    }
    
    int lo = 0, hi = 1e8;
    while(lo != hi){
        int mid = lo + (hi - lo + 1)/2;
        BigNum b(to_string(mid));
        if(ans.n.multiply(b) <= ans.d) lo = mid;
        else hi = mid - 1;
    }
    BigNum b(to_string(-lo));
    ans.d = ans.d.add(ans.n.multiply(b));
    BigNum aux1("10");
    string dec;
    for(int i=1;i<=7;i++){
        ans.d = ans.d.multiply(aux1);
        for(int j=9;j>=0;j--){
            BigNum aux2(to_string(-j));
            if(ans.n.multiply(aux2) <= ans.d){
                dec += '0' + j;
                ans.d = ans.d.add(ans.n.multiply(aux2));
                break;
            }
        }
    }
    auto upup = [&](string &s){
        for(int i=5;i>=0;i--){
            if(s[i] == '9'){
                s[i] = '0';
                if(i == 0){
                    lo++;
                }
            }else{
                s[i]+=1;
                break;
            }
        }
    };
    BigNum zr("0");
    if(ans.d == zr){
        if(dec[6] == '5'){
            if((dec[5]-'0') % 2 == 1){
                //the half to even thing.. round up
                upup(dec);
            }
            
        }else if(dec[6] > '5'){
            //Round up
            upup(dec);
        }
    }else{
        if(dec[6] >= '5'){
            //Round up
            upup(dec);
        }
    }
    cout << lo << "." << dec.substr(0, 6) << "\n";
    // ans.d.print();
    // ans.n.print();
    // cout << ans << "\n";
}
