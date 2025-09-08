#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 31607;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u;
        // v = u % MOD;
        // if (v < 0) v += MOD;
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
    Mint& operator*= (const Mint &u){ v = (u.v * v) % MOD; return *this;}
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


int n;
void fwht(vector<Mint> &a) { 
    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        for(int j = 0; j < n; j += M) {
            for(int l = j; l < K + j; ++l){
                a[l + K] += a[l];
            }
        }
    }
}

void fwhtinverse(vector<Mint> &a) { 
    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        for(int j = 0; j < n; j += M) {
            for(int l = j; l < K + j; ++l){
                a[l + K] -= a[l];
            }
        }
    }
}

void multiply(vector<Mint> &a, vector<Mint> &b) { //just one example of task, sometimes you don't want multiply!
    fwht(a);
    fwht(b);
    for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
    fwhtinverse(a);
}

Mint invx[10000];
int gr[21][21];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int nn;
    cin >> nn;
    for(int i=0;i<nn;i++){
        for(int j=0;j<nn;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=1;i<=9999;i++) invx[i] = Mint(1) / i;
    n = 1 << (nn + 2);
    vector<Mint> ca(n);
    vector<Mint> cdp(n);
    ca[0] = 1;
    //better to calculate the probability of losing!
    Mint inv = 1;
    Mint mtp = 1;
    for(int j=0;j<nn;j++){
        inv /= 10000;
        mtp *= 10000;
    }
    fwht(ca);
    for(int i=0;i<nn;i++){
        for(int j=0;j<n;j++) cdp[j] = 0;
        
        int b1 = i, b2 = nn - 1 - i;
        for(int j=1;j<(1 << nn); j++){
            Mint cur = 1;
            if(__builtin_popcount(j) == 1){
                for(int k=0;k<nn;k++){
                    if(j & (1 << k)) cur *= (10000 - gr[i][k]);
                    else cur *= gr[i][k];
                }
            }else{
                int bt = 31-__builtin_clz(j);
                cur = cdp[j ^ (1 << bt)] * mtp;
                cur *= (10000 - gr[i][bt]);
                cur *= invx[gr[i][bt]];
            }
            cdp[j] = cur * inv;
        }
        for(int j=1;j<(1 << nn); j++){
            int cj = j;
            if(j & (1 << b1)) cj |= (1 << nn);
            if(j & (1 << b2)) cj |= (1 << (nn+1));
            if(j != cj){
                cdp[cj] = cdp[j];
                cdp[j] = 0;
            }
        }
        fwht(cdp);
        for(int j = 0; j < n; j++) ca[j] = ca[j] * cdp[j];
    }
    fwhtinverse(ca);
    cout << 1 - ca[n - 1] << "\n";
}