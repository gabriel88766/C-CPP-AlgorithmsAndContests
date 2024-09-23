#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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
    ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
        if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
            x = 1; y = 0;
            return a;
        }
        ll d = gcd_euclid(b, a % b, y, x); //if b > a then this step reverses it
        y -= x * (a/b); 
        return d;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    /*Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}*/
    Mint operator/= (Mint u){ //division , MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};
const int N = 1e5+3;
int aa[N], cc[N], qm[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    Mint ans = 0;
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    for(int i=1;i<=n;i++){
        aa[i] = aa[i-1];
        cc[i] = cc[i-1];
        qm[i] = qm[i-1];
        if(s[i] == 'A') aa[i]++;
        else if(s[i] == 'C') cc[i]++;
        else if(s[i] == '?') qm[i]++;
    }
    for(int i=1;i<=n;i++){
        int pa = aa[i-1];
        int sc = cc[n] - cc[i];
        int pq = qm[i-1];
        int sq = qm[n] - qm[i];
        if(s[i] == 'B' || s[i] == '?'){
            //anyway, I want the case s[i] == 'B', has ABC centered in i
            // 2^pq * pa + (pq, 1) * 2 ^ (pq-1) * (pa + 1) + (pq, 2) * 2^(pq-2) * (pa + 2) + ...
            // 3^pq * pa +  sum C(pq, i) * 2^(pq-i) * i
            Mint f1 = Mint(3).pow(pq) * pa;
            if(pq) f1 += Mint(3).pow(pq - 1) * pq;
            Mint f2 = Mint(3).pow(sq) * sc;
            if(sq) f2 += Mint(3).pow(sq - 1) * sq;
            ans += f1 * f2;
        }
    }
    cout << ans << "\n";
}
