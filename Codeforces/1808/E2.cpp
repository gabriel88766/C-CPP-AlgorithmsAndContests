#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
ll MOD;

struct Mint{
    ll v;
    //static const int MOD = MOD_val;
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

vector<Mint> multPoly(vector<Mint> &a, vector<Mint> &b){
    int size = a.size();
    vector<Mint> ans(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ans[(i+j) % size] += a[i] * b[j];
        }
    }
    return ans;
}

vector<Mint> binpow(vector<Mint> a, ll b){
    int size = a.size();
    vector<Mint> ans(size, 0); //idt
    ans[0] = 1;

    while(b > 0){
        if(b & 1) 
            ans = multPoly(ans, a);
        a = multPoly(a, a);
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k >> MOD;
    Mint ans = 0;
    if(k % 2){
        for(int i=0;i<k;i++){
            // i,  x|i
            // === k^n - (k-1)^n
            ans += Mint(k).pow(n-1) - Mint(k-1).pow(n-1);
            // ~i,  i
            vector<Mint> poly(k, 1);
            poly[i] = 0;
            poly = binpow(poly, n-1); //O(k^3 * log (n)) could be O(k^2 * log(k) * log(n)) fft
            ans += poly[i];
        }
    }else{
        for(int i=0;i<k/2;i++){
            int i1 = i, i2 = i+k/2;
            //i1|i2,  x | i1 | i2
            ans += Mint(k).pow(n-1) - Mint(k-2).pow(n-1);
            //~i1&~i2, i1 | i2
            //sum i1 or i2 not using i1 nor i2
            vector<Mint> poly(k, 1);
            poly[i1] = poly[i2] = 0;
            poly = binpow(poly, n-1);
            ans += poly[i1] + poly[i2];
        }
    }
    cout << ans << "\n";
}