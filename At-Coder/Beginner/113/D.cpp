#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
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
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

Mint dp[105][256][10];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, k;
    cin >> h >> w >> k;
    vector<int> allw;
    for(int i = 0; i < (1 << (w-1)); i++){
        bool ok = true;
        for(int j=0;j<w;j++){
            if((i & (1 << j)) && (i & (1 << (j+1)))) ok = false;
        }
        if(ok) allw.push_back(i);
    }
    dp[0][0][1] = 1;

    for(int i = 1; i <= h; i++){
        for(int j=1;j<=w;j++){
            Mint cur = 0;
            for(auto any : allw) cur += dp[i-1][any][j];
            for(auto msk : allw){ //from 0 to (1 << (w-1)) - 1
                int nj = j;
                if(msk & (1 << (nj - 1))) nj++;
                else if(nj > 1 && (msk & (1 << (nj - 2)))) nj--;
                dp[i][msk][nj] += cur;
            }
        }
    }
    Mint ans = 0;
    for(auto any : allw) ans += dp[h][any][k];
    cout << ans << "\n";
}
