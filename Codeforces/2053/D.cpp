#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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
        vector<pair<int,int>> va(n), vb(n);
        vector<int> ia(n+1), ib(n+1);
        vector<int> minv(n);
        for(int i=0;i<n;i++){
            cin >> va[i].first;
            va[i].second = i + 1;
        }
        for(int i=0;i<n;i++){
            cin >> vb[i].first;
            vb[i].second = i + 1;
        }
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        for(int i=0;i<n;i++) minv[i] = min(va[i].first, vb[i].first);
        for(int i=0;i<n;i++){
            ia[va[i].second] = i;
            ib[vb[i].second] = i;
        }
        Mint ans = 1;
        for(int i=0;i<n;i++) ans *= minv[i];
        cout << ans << " ";
        for(int i=0;i<q;i++){
            int o, x;
            cin >> o >> x;
            int fi, si = -1;
            vector<pair<int,int>> &xv = (o == 1 ? va : vb);
            vector<int> &iv = (o == 1 ? ia : ib);
            fi = iv[x];
            xv[fi].first++;
            if(fi + 1 < n && xv[fi+1].first < xv[fi].first){
                si = fi + 1;
                for(int j=n/2;j>=1;j>>=1){
                    while(si + j < n && xv[si + j].first < xv[fi].first) si += j;
                }
            }
            
            if(si != -1){
                swap(xv[si], xv[fi]);
                iv[x] = si;
                iv[xv[fi].second]  = fi;
                ans /= minv[si];
                ans /= minv[fi];
                minv[si] = min(va[si].first, vb[si].first);
                minv[fi] = min(va[fi].first, vb[fi].first);
                ans *= minv[si];
                ans *= minv[fi];
            }else{
                ans /= minv[fi];
                minv[fi] = min(va[fi].first, vb[fi].first);
                ans *= minv[fi];
            }
            
            cout << ans << " ";
        }
        cout << "\n";
    }
}
