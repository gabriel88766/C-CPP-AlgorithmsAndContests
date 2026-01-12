#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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
void multiply(vector<Mint> &a, vector<Mint> b) {
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
}
    
void mod(vector<Mint> &vec, int k){
    vector<Mint> red(vec.size());
    Mint aux = 0;
    for(int j=vec.size()-1;j>=0;j--){
        aux -= red[j];
        vec[j] += aux;
        if(j >= k){
            aux += vec[j];
            if(j != k) red[j - k - 1] = vec[j];
            vec[j] = 0;
        }
    }
    while(vec.size() > 1 && vec.back() == 0) vec.pop_back();
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input


    ll n, k;
    cin >> k >> n;
    vector<Mint> ans(1);
    ans[0] = 1;
    vector<Mint>cx(2);
    cx[1] = 1;
    for(int i = 0; i < 60; i++){
        // cout << i << endl;
        if(n & (1LL << i)){
            cx[0] += 1;
            multiply(ans, cx);
            mod(ans, k);
            cx[0] -= 1;
        }
        if(i != 59){
            multiply(cx, cx);
            mod(cx, k);
        }
    }
    Mint rans = 0;
    for(int j=0;j<k;j++){
        if(j < ans.size()) rans += ans[j];
    }
    cout << rans << "\n";
}
