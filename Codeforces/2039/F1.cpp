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

const int N = 100000;
vector<int> dv[N + 5];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            dv[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        vector<vector<Mint>> tr(m+1);
    
        for(int i=1;i<=m;i++){
            tr[i].resize(m/i + 1);
        }
        for(int i=m;i>=1;i--){
            for(int j=dv[i].size()-1;j>=0;j--){
                int ax = i/dv[i][j];
                assert(ax < tr[dv[i][j]].size());
                tr[dv[i][j]][ax] = m/dv[i][j];
                for(auto &x : dv[ax]){
                    if(x != 1){
                        tr[dv[i][j]][ax] -= tr[dv[i][j]*x][ax/x];
                    }
                }
            }
        }
        vector<Mint> dp(m+1, 1);
        Mint ans = m;
        int xp = 1;
        while(dp[1] != 0){
            // xp++;
            Mint cur = Mint(2).pow(xp);
            vector<Mint> ndp(m+1);
            for(int i=1;i<=m;i++){
                for(int j=2;j<=m/i;j++){
                    ndp[i] += dp[i*j] * tr[i][j];
                }
            }
            for(int i=1;i<=m;i++) cout << dp[i] << " ";
            cout << "\n";
            dp = ndp;
            for(int i=1;i<=m;i++) ans += dp[i] * cur;
        }
        cout << ans << "\n";
    }
}   
