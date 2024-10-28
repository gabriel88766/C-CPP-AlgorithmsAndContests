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

Mint p2m[8000002];
ll p2[61];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    p2m[0] = 1;
    for(int i=1;i<=8000000;i++) p2m[i] = p2m[i-1] * 2;
    p2[0] = 1;
    for(int i=1;i<=60;i++) p2[i] = p2[i-1] * 2;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> q2(n+1), v(n+1), ps(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            while(!(v[i] % 2)){
                v[i] /= 2;
                q2[i]++;
            }
            ps[i] = ps[i-1] + v[i];
        }
        vector<pair<int,int>> vp;
        for(int i=1;i<=n;i++){
            vp.push_back({i, q2[i]});
            while(vp.size() >= 2){
                int ib = vp.size() - 1;
                int oi = vp.size() - 2;
                auto [j, qnt] = vp[ib];
                if(qnt >= 30 || p2[qnt] * v[j] >= v[vp[oi].first]){
                    vp.pop_back();
                    vp[oi].first = j;
                    vp[oi].second += qnt;
                }else break;
            }
            if(vp.back().second == 0) vp.pop_back();
            Mint ans = ps[i];
            for(auto [j, qnt] : vp){
                ans -= v[j];
                ans += v[j] * p2m[qnt];
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
