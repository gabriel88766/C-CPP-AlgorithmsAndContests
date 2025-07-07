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

const int N = 5005;
Mint tr[N][N];
bool ds[N][N];
bool can1[N][N];
Mint dp[N], dpaux[N][N], ps[N][N];
bool can[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    dp[0] = 1;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> dsl;
        vector<vector<int>> ods(n+1);
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            dsl.push_back({a, b});
            ds[a][b] = true;
            ods[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                //set to can
                can1[i][j] = true;
            }
        }
        for(auto [a, b] : dsl){
            if(a >= b){
                for(int x=a;x<=n;x++){
                    can1[a-b + 1][x] = false;
                }
            }
        }   

        
        for(int i=1;i<=n;i++){
            Mint ctr = 0;
            
            for(int j=1;j<=i;j++) can[j] = true;
            if(!can1[i][i]) can[i] = false;
            for(auto x : ods[i]){
                if(x <= i) can[i-x+1] = false;
            }
            for(int j=i-1;j>=0;j--){
                if(can[j+1]) ctr += 1;
                int len = i - j;
                for(auto x : ods[j]){
                    if(x <= j) can[j-x+1] = false;
                    //Need to be O(1)
                    //    8, 9, 10, 11, 1, 2, 3, 4, 5, 6, 7
                    //8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7
                    //     k, k+1, k+2, ...,m-1, m, 1, 2, 3, ..., k-1
                    // k, k+1, k+2, k+3,..., m, m+1, 1, 2, 3, ..., k-1
                    //     k+1, k+2,k+3, .., m, 1, 2, 3, .... ,k-1, k
                    //what if first part
                    //x x+1 x+2, 1, 2 (x = 3, len = 5) j + len - x + 1
                    if(x >= len){

                    }
                }

                
                dp[i] += dp[j] * ctr;
                if(can1[j+1][i]){
                    dpaux[i][len] += dp[j];
                    dp[i] -= ps[j][n] - ps[j][len];
                }
            }
            for(int j=1;j<=n;j++) ps[i][j] = ps[i][j-1] + dpaux[i][j];
        }
        Mint ans = 0;
        cout << dp[n] << "\n";
        for(int i=1;i<=n;i++){
            dp[i] = 0;
            for(int j=1;j<=n;j++){
                tr[i][j] = 0;
                can1[i][j] = false;
                ds[i][j] = false;
                dpaux[i][j] = 0;
                ps[i][j] = 0;
            }
        }
    }
}
