#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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

// if MOD 786433, w = 5 and change to 1 << 18
void ntt(vector<Mint> &a, int n, int s) { //31^(2^23) == 1 (mod 998244353), so, for example, if n = 2^16, w1 = 31^(2^7)
    Mint w1 = 31;
    for(int i = n; i < (1 << 23); i <<= 1) w1 *= w1;
    for (int i=0, j=0; i<n; i++) {
        if (i>j) swap(a[i], a[j]);
        for (int l=n/2; (j^=l) < l; l>>=1);
    }
    //w1^n = 1
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


pair<vector<Mint>, vector<Mint>> multiply3(pair<vector<Mint>, vector<Mint>>  a, pair<vector<Mint>, vector<Mint>>  b) {
    vector<Mint> a0 = a.first;
    vector<Mint> a1 = a.second;
    vector<Mint> b0 = b.first;
    vector<Mint> b1 = b.second;
    int n = 1;
    while(n < max(a0.size(), a1.size()) + max(b0.size(), b1.size()) - 1) n *= 2;
    a0.resize(n);
    a1.resize(n);
    b0.resize(n);
    b1.resize(n);
    ntt(a0,n,1);
    ntt(a1, n, 1);
    ntt(b0, n, 1);
    ntt(b1, n, 1);
    vector<Mint> res0(n), res1(n);
    for (int i = 0; i < n; i++){
        res0[i] = a0[i] * b0[i] + a1[i] * b1[i];
        res1[i] = a0[i] * b1[i] + a1[i] * b0[i];
    }
    ntt(res0,n,-1);
    ntt(res1,n,-1);
    for (int i = 0; i < n; i++){
        res0[i] /= n;
        res1[i] /= n;
    }
    while(res0.back() == 0) res0.pop_back();
    while(res1.back() == 0) res1.pop_back();
    return {res0, res1};
}


pair<vector<Mint>, vector<Mint>> pow(pair<vector<Mint>, vector<Mint>>  a, int m) {
    vector<Mint> a0 = a.first;
    vector<Mint> a1 = a.second;
    vector<Mint> b0(1, 1);
    vector<Mint> b1(0, 0);
    int n = 1;
    while(n < m*max(a0.size(), a1.size()) + max(b0.size(), b1.size()) - 1) n *= 2;
    a0.resize(n);
    a1.resize(n);
    b0.resize(n);
    b1.resize(n);
    ntt(a0,n,1);
    ntt(a1, n, 1);
    ntt(b0, n, 1);
    ntt(b1, n, 1);
    vector<Mint> res0(n), res1(n);
    Mint inv = Mint(1)/2;
    for (int i = 0; i < n; i++){
        Mint v1 = (a0[i] + a1[i]).pow(m);
        Mint v2 = (a0[i] - a1[i]).pow(m);
        res0[i] = b0[i] * ((v1+v2)*inv) + b1[i] * ((v1-v2)*inv);
        res1[i] =  b1[i] * ((v1+v2)*inv) + b0[i] * ((v1-v2)*inv);
    }
    ntt(res0,n,-1);
    ntt(res1,n,-1);
    for (int i = 0; i < n; i++){
        res0[i] /= n;
        res1[i] /= n;
    }
    while(res0.back() == 0) res0.pop_back();
    while(res1.back() == 0) res1.pop_back();
    return {res0, res1};
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> cnt(11);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    vector<Mint> ans0(1, 1);
    vector<Mint> ans1(0, 0);
    vector<pair<vector<Mint>, vector<Mint>>> sm; 
    for(int i=1;i<=10;i++){
        if(cnt[i] == 0) continue;
        vector<Mint> aux0(1, 1), aux1(i+1, 0);
        aux1[i] = 1;
        sm.push_back(pow({aux0, aux1}, cnt[i]));
    }
    for(auto [a, b] : sm){
        auto px = multiply3({a, b}, {ans0, ans1});
        ans0 = px.first;
        ans1 = px.second;
    }
    if(ans1.size() > m ) cout << ans1[m] << "\n";
    else cout << 0 << "\n";
}
