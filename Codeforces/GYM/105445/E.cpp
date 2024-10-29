//NOT INTENDED
//BUT AC :)
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

const int N = 2e6+3;
Mint ans[N];
Mint ps1[N], ps2[N];
ll a[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<pair<int,int>> vq(q+1);
        vector<int> qr;
        for(int i=1;i<=q;i++){
            int a, b;
            cin >> a >> b;
            vq[i] = {a, b};
            qr.push_back(i);
        }
        function<void(int,int,vector<int>)> dc = [&](int l, int r, vector<int> qq){
            if(!qq.size()) return;
            if(l == r){
                for(auto x : qq){
                    ans[x] = a[vq[x].first];
                }
                return;
            }
            int m = (l + r)/2;
            vector<int> qc, ql, qr;
            for(auto x : qq){
                auto [a, b] = vq[x];
                if(b <= m) ql.push_back(x);
                else if(a > m) qr.push_back(x);
                else qc.push_back(x);
            }
            dc(l, m, ql);
            dc(m+1, r, qr);
            if(!qc.size()) return;
            Mint pr = 1, spr = 0, ps;
            for(int i=m+1;i<=r;i++){
                pr *= a[i];
                spr += pr;
                ps1[i] = spr;
            }
            pr = 1, spr = 0;
            for(int i=m;i>=l;i--){
                pr *= a[i];
                spr += pr;
                ps1[i] = spr;
            }
            spr = 0, ps = 0;
            for(int i=m+1;i<=r;i++){
                ps *= a[i];
                ps += a[i];
                spr += ps;
                ps2[i] = spr;
            }
            spr = 0, ps = 0;
            for(int i=m;i>=l;i--){
                ps *= a[i];
                ps += a[i];
                spr += ps;
                ps2[i] = spr;
            }
            for(auto x : qc){
                auto [a, b] = vq[x];
                assert(a <= m && b > m && b <= r && a >= l);
                ans[x] = ps1[a] * ps1[b] + ps2[a] + ps2[b];
            }
        };

        dc(1, n, qr);

        for(int i=1;i<=q;i++) cout << ans[i] << "\n";
    }
}
