#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};


const int N = 12252240;
Mint dp2[N][2];
Mint d1 , d3;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, a, x, y, k, m;
    cin >> n >> a >> x >> y >> k >> m;
    for(int j=k+1;j>=1;j--){
        int b = j & 1;
        if(j == k + 1){
            d1 = 1;
        }else{
            int r = 0;
            
            for(int i=0;i<N;i++){
                dp2[i][b] = dp2[i][b^1] * (n-1) + dp2[i-r][b^1] + i * d1; 
                r++;
                if(r >= j) r -= j;
            }
            d3 = d3 * n + d1;
            d1 *= n;
        }
    }

    
    Mint ans = 0;
    for(int i=0;i<n;i++){
        int r = a % N;
        ans += dp2[r][1] + (d3) * (a / N) * N;
        a = (a *x + y) % m;
    }
    cout << ans << "\n";
}
