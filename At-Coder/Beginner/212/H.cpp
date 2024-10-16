#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
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
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

void fwht(vector<Mint> &a, int lo, int hi) { 
    if(lo == (hi-1)) return;
    //w1^n = 1
    int mid = lo + (hi-lo)/2;
    fwht(a, lo, mid);
    fwht(a, mid, hi);
    for(int i = 0; lo+i < mid; i++){
        Mint x = a[lo+i];
        Mint y = a[mid+i];
        a[lo+i] = x + y;
        a[mid+i] = x - y; 
    } 
}

void multiply(vector<Mint> &a, vector<Mint> &b) { 
    fwht(a,0,n);
    fwht(b,0,n);
    for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
    fwht(a,0,n);
    for (int i = 0; i < n; i++) a[i] = a[i]/n;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m, k;
    cin >> m >> k;
    vector<int> v(k+1);
    for(int i=1;i<=k;i++) cin >> v[i];
    n = 1 << 16;
    vector<Mint> a(n);
    for(int i=1;i<=k;i++){
        a[v[i]].v = 1;
    }
    fwht(a, 0, n);
    for(int i=0;i<n;i++){
        if(a[i].v == 0) a[i] = 0;
        else if(a[i].v == 1) a[i] = m;
        else{
            a[i] = (a[i].pow(m+1) - 1)/(a[i]-1) - 1;
        }
    }
    fwht(a, 0, n);
    for(int i=0;i<n;i++) a[i] /= n;
    Mint ans = 0;
    for(int i=1;i<n;i++) ans += a[i];

    cout << ans;
   
}
