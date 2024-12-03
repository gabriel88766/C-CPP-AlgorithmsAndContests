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


const int N = 6e5+2; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int,int>> vp;
        vp.push_back({0, 0});
        for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            vp.push_back({n-a, m-b});
        }
        vp.push_back({n, m});
        sort(vp.begin(), vp.end());
        vector<vector<Mint>> tr(k+2, vector<Mint>(k+2));
        for(int i=0;i<=k+1;i++){
            for(int j=i+1;j<=k+1;j++){
                auto [a1, b1] = vp[j];
                auto [a2, b2] = vp[i];
                if(a1 >= a2 && b1 >= b2){
                    tr[i][j] = nCr(a1+b1-b2-a2, b1-b2);
                    for(int u=i+1;u<j;u++){
                        auto [a3, b3] = vp[u];
                        if(a1 >= a3 && b1 >= b3){
                            tr[i][j] -= tr[i][u] * nCr(a1+b1-a3-b3, a1-a3);
                        }
                    }
                }
                // cout << tr[i][j] << " ";
            }
            // cout << "\n";
        }
        vector<Mint> dp1(k+2), dp2(k+2);
        dp1[0] = 1;
        dp2[0] = 0;
        for(int i=1;i<=k+1;i++){
            Mint mult = (i == k+1 ? 1 : 2);
            for(int j=0;j<i;j++){
                // cout << tr[j][i] << " " << 2*(vp[i].first - vp[j].first) << " " <<  (vp[i].second - vp[j].second) <<"\n";
                dp1[i] += dp1[j] * tr[j][i];
                dp2[i] += tr[j][i] * (dp2[j] + dp1[j] * (2*(vp[i].first - vp[j].first) + (vp[i].second - vp[j].second)));
            }
            dp2[i] *= mult;
            // cout << dp2[i] << "\n";
        }
        cout << dp2[k+1]/nCr(n+m,n) << "\n";
    }
}
