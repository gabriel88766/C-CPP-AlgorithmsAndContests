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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<Mint> a(n+1), b(m+1), ps(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i].v;
        ps[i] = ps[i-1] + a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i].v;
    }
    Mint ans = 0, aux = 0;
    for(int i=1;i<=n;i++){
        ans += a[i] * i;
    }
    for(int i=1;i<=m;i++){
        aux += b[i];
    }
    ans *= aux;
    for(int i=1;i<=m;i++){
        for(int j=1;i*j<=n;j++){
            int imin = i * j;
            int imax = min(imin + i - 1, n);
            // if(i == 1) cout << imin << " " << imax << "\n";
            ans -= b[i] * (ps[imax] - ps[imin-1]) * (i * j);
        }
    }

    cout << ans << "\n";
}
