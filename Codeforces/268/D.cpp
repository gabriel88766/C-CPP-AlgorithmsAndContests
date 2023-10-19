#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+9;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

Mint dp[2][2][31][31][31];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input

    dp[0][0][0][0][0] = 1;
    int n, h;
    cin >> n >> h;
    Mint ans = 0;
    for(int i=1;i<=n;i++){//maybe [1,0]
        for(int a=0;a<=h;a++){
            for(int b=a;b<=h;b++){
                for(int c=b;c<=h;c++){
                    //current state, dp[i-1][0|1][a][b][c]
                    dp[i&1][0][min(a+1, h)][min(b+1, h)][min(c+1, h)] += dp[(i-1)&1][0][a][b][c];
                    dp[i&1][a == h ? 1 : 0][1][min(b+1,h)][min(c+1, h)] += dp[(i-1)&1][0][a][b][c];
                    dp[i&1][b == h ? 1 : 0][1][min(a+1,h)][min(c+1, h)] += dp[(i-1)&1][0][a][b][c];
                    dp[i&1][c == h ? 1 : 0][1][min(a+1,h)][min(b+1, h)] += dp[(i-1)&1][0][a][b][c];
                    dp[i&1][1][min(a+1, h)][min(b+1, h)][min(c+1, h)] += dp[(i-1)&1][1][a][b][c];
                    dp[i&1][a == h ? 1 : 0][min(b+1,h)][min(c+1, h)][h] += dp[(i-1)&1][1][a][b][c];
                    dp[i&1][b == h ? 1 : 0][min(a+1,h)][min(c+1, h)][h] += dp[(i-1)&1][1][a][b][c];
                    dp[i&1][c == h ? 1 : 0][min(a+1,h)][min(b+1, h)][h] += dp[(i-1)&1][1][a][b][c];
                    dp[(i-1)&1][0][a][b][c] = dp[(i-1)&1][1][a][b][c] = 0;
                }
            }
        }
    }
    for(int a=0;a<=h;a++){
        for(int b=a;b<=h;b++){
            for(int c=b;c<=h;c++){
                if(a != h) ans += dp[n&1][1][a][b][c];
                ans += dp[n&1][0][a][b][c];
            }
        }
    }
    cout << ans << "\n";
}
