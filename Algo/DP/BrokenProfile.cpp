#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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

vector<vector<Mint>> dp(1005, vector<Mint>(1024, 0));
int n, m;

void calc(int x, int y, int mask, int nxt_mask){
    if(y == n){
        dp[x+1][nxt_mask] += dp[x][mask];
    }else{
        int cur = 1 << y;
        //2x1
        if(mask & cur){
            //cant 
            calc(x, y+1, mask, nxt_mask);
        }else{
            //can 1x2
            calc(x, y+1, mask, nxt_mask | cur);
            if(y+1 < n && !(mask & (cur << 1))){ // can 2x1
                calc(x, y+2, mask, nxt_mask);
            }
        }
    }
}

//Counting Tiles, CSES
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m;
    // m up to 1000, n up to 10, complexity (1+phi) ^ n * m
    dp[0][0] = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j < (1 << n); j++){ 
            calc(i, 0, j, 0);
        }
    }
    cout << dp[m][0];
}
