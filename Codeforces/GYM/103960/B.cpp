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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
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

vector<pair<int,int>> seg;
void makeseg(int i, int j, int l = 0, int r = (1 << 30) - 1, int len = 30){
    if(l > j || r < i) return;
    assert(r-l+1 == 1 << len);
    if(l >= i && r <= j){
        seg.push_back({l, len});
        return;
    }
    int m = (l + r) >> 1;
    makeseg(i, j, l, m, len - 1);
    makeseg(i, j, m+1, r, len - 1);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int l1, r1, l2, r2, l3, r3;
    cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;
    makeseg(l1, r1);
    auto seg1 = seg;
    seg.clear();
    makeseg(l2, r2);
    auto seg2 = seg;
    seg.clear();
    Mint ans = 0;
    for(auto [a, b] : seg1){
        for(auto [c, d] : seg2){
            int cur = a ^ c;
            int xmin = 1 << b;
            int xmax = 1 << d;
            if(xmin > xmax) swap(xmin, xmax);
            int minv = cur & (-(xmax));
            int maxv = cur | (xmax-1);
            ll inters = min(maxv, r3) - max(minv, l3);
            inters = max(inters + 1, 0LL);
            ans += inters * xmin;
        }
    }
    ans /= (r1 - l1 + 1);
    ans /= (r2 - l2 + 1);
    ans /= (r3 - l3 + 1);
    cout << 1-ans << "\n";
}
