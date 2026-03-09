#include <bits/stdc++.h>

#pragma GCC optimize("O2,fast-math,unroll-loops")

using namespace std;

#if defined(MOG_LIB)
using namespace mog;
#endif

using ll = long long;

#define int ll

#if defined(MOG_LOCAL)
#include <mog/debug.hpp>
#else
#define dbg(...) 42
#define dbgif(...) 42
#endif

using ld = long double;

const int MOD = 1e9 + 7;
const ld eps = 1e-9;

mt19937 rng(random_device{}());


long double PI = acosl(-1.0);
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
    BigNum negate(){
        BigNum ans = *this;
        ans.s = ans.s == 1 ? -1 : 1;
        return ans;
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
    bool operator< (BigNum b){
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
    //call add instead => a.sub(b) = a.add(b.negate());
    BigNum sub(BigNum b){
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
    BigNum multiply(BigNum b){
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



struct Frac{
    BigNum a, b;
    Frac(BigNum a, BigNum b){
        this->a = a;
        this->b = b;
    }
    Frac operator+ (Frac v){
        Frac res = Frac(a.multiply(v.b).add(b.multiply(v.a)), b.multiply(v.b));
        return res;
    }
    bool operator< (Frac v){
        return a.multiply(v.b).sub(b.multiply(v.a)) < BigNum("0");
    }
};


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	{
		map<int, int> last;
		for (int i = 0; i < n; i++) {
			if (last.count(a[i])) {
				cout << "Yes" << endl;
				cout << 1 << endl;
				cout << last[a[i]] + 1 << endl;
				cout << i + 1  << endl;
				return 0;
			}
			last[a[i]] = i;
		}
	}
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] > a[j]; });
	while (n > 23) ord.pop_back(),n--;
	vector<vector<pair<ld, int>>> vals(n + 1);
	for (int mask = 1; mask < 1 << n; mask++) {
		if (popcount(unsigned(mask)) * 2 > n) continue;
		ld val = 0;
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1) {
				val += 1.0 / a[ord[i]];
			}
		}
		vals[popcount(unsigned(mask))].emplace_back(val, mask);
	}
	for (int size = 1; 2 * size <= n; size++) {
		sort(vals[size].begin(), vals[size].end());
	}
	for (int size = 1; 2 * size <= n; size++) {
		for (int i = 1; i < vals[size].size(); i++) {
			if (vals[size][i].first - vals[size][i - 1].first <= 1e-5 + eps) {
                Frac f1 = {BigNum("0"), BigNum("1")}, f2 = {BigNum("0"), BigNum("1")};
                for(int j = 0;j < n; j++){
                    auto &m1 = vals[size][i-1].second;
                    auto &m2 = vals[size][i].second;
                    if(m1 & (1 << j)){
                        f1 = f1 + Frac(BigNum("1"), to_string(a[ord[j]]));
                    }
                    if(m2 & (1 << j)){
                        f2 = f2 + Frac(BigNum("1"), to_string(a[ord[j]]));
                    }
                }
                BigNum up = f1.b.multiply(f2.a).add(f1.a.multiply(f2.b).negate());
                BigNum down = f1.b.multiply(f2.b);
                if(down < up.multiply(BigNum("100000"))) continue;

				cout << "Yes" << endl;
				auto conv = [&](int mask) -> vector<int> {
					vector<int> x;
					for (int i = 0; i < n; i++) {
						if (mask >> i & 1) x.push_back(ord[i]);
					}
					sort(x.begin(), x.end());
					return x;
				};
				auto x = conv(vals[size][i - 1].second);
				auto y = conv(vals[size][i].second);
				cout << size << endl;
				for (int i: x) cout << i + 1 << ' ';
				cout << endl;
				for (int i: y) cout << i + 1 << ' ';
				cout << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
    return 0;
}

