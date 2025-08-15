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
    Mint(int u){ 
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

const int N = 2e5+35;
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<Mint> dp(n+1, 0);
    vector<Mint> aux(n+1, 0);
    vector<Mint> ps(n+1, 0);
    dp[0] = 1;
    int mx = 0;
    for(int i=1;i<N;i++){
        for(int j=0;j<=mx+cnt[i];j++) aux[j] = 0;
        for(int j=0;j<=mx;j++){
            aux[j + cnt[i]] = dp[j];
            dp[j] = 0;
        }
        for(int j=0;j<=mx+cnt[i];j++){
            ps[j] = aux[j];
            if(j > 0) ps[j] += ps[j-1];
        }
        int nmx = (mx + cnt[i]) / 2;
        for(int j=0;j<=nmx;j++){
            dp[j] = ps[mx+cnt[i]];
            if(j > 0) dp[j] -= ps[2*j - 1];
        }
        mx = nmx;
    }
    cout << dp[0] << "\n";
}
