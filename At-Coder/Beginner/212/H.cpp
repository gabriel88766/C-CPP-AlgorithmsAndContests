#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
ll binpow(ll a, ll b, ll m = MOD){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

struct Mint{
    ll v;
    Mint(){ v = 0;}
    Mint(ll u){ v = u%MOD;}
    Mint operator* (Mint u){ return Mint((v*u.v) % MOD);}
    Mint operator+ (Mint u){ return Mint((v+u.v >= MOD ? v+u.v-MOD : v+u.v));}
    Mint operator- (Mint u){ return Mint((v-u.v >= 0 ? v-u.v : v-u.v+MOD));}
    Mint operator/ (Mint u){ return Mint((v*binpow(u.v, MOD-2)));}
};

//change to ntt
void xorfft(vector<Mint> &a, int lo, int hi) { 
    
    if(lo == (hi-1)) return;
    //w1^n = 1
    int mid = lo + (hi-lo)/2;
    xorfft(a, lo, mid);
    xorfft(a, mid, hi);
    for(int i = 0; lo+i < mid; i++){
        Mint x = a[lo+i];
        Mint y = a[mid+i];
        a[lo+i] = x + y;
        a[mid+i] = x - y;
    }
}

void multiply(vector<Mint> &a, vector<Mint> &b) {
    xorfft(a,0,n);
    xorfft(b,0,n);
    for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
    xorfft(a,0,n);
    for (int i = 0; i < n; i++) a[i] = a[i]/n;
}

void inv(vector<Mint> &a){
    vector<Mint> aux(n);
    aux[0] = 1;
    xorfft(a, 0, n);
    xorfft(aux, 0, n);
    for(int i=0;i<n;i++) a[i] = aux[i]/a[i];
    xorfft(a, 0, n);
    for (int i = 0; i < n; i++) a[i] = a[i]/n;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m, k;
    vector<int> v(k+1);
    cin >> m >> k;
    for(int i=1;i<=k;i++) cin >> v[i];
    n = 1 << 16;
    vector<Mint> a(n);
    for(int i=1;i<=k;i++){
        a[v[i]].v = 1;
    }
    vector<Mint> b = a;
    b[0] = b[0] - 1;
    for(int i=0;i<=8;i++) cout << b[i].v << " ";
    auto x = b;
    inv(b);
    cout << "\n";
    for(int i=0;i<=8;i++) cout << b[i].v << " ";
    cout << "\n";
    multiply(x,b);
    for(int i=0;i<=8;i++) cout << x[i].v << " ";
    cout << "\n\n";
    Mint ans = 0;
    vector<Mint> ansv(n,0);
    ansv[0] = 1;
    for(int i=1;i<=m+1;i++){
        auto aux = a;
        multiply(ansv, a);
        a = aux;
    }
    ansv[0] = ansv[0]-1;
    multiply(ansv, b);
    // for(int i=0;i<=8;i++) cout << ansv[i].v << " ";
    // cout << "\n";
    for(int i=1;i<n;i++) ans = ans + ansv[i];
    
    cout << ans.v;
   
}
