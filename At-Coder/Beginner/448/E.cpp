#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 10007; //1e9+7
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
        if(u < 0) return (Mint(1)/v).pow(-u);
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

int adv1[10007][10][30], adv2[10007][10][30];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int k, m;
    cin >> k >> m;

    for(int x=0;x<30;x++){
        for(int i=0;i<10007;i++){
            for(int j=0;j<10;j++){
                if(x == 0) adv1[i][j][x] = (10 * i + j) % 10007;
                else adv1[i][j][x] = adv1[adv1[i][j][x-1]][j][x-1];
            }
        }
    }
    for(int x=0;x<30;x++){
        for(int i=0;i<m;i++){
            for(int j=0;j<10;j++){
                if(x == 0) adv2[i][j][x] = (10 * i + j) % m;
                else adv2[i][j][x] = adv2[adv2[i][j][x-1]][j][x-1];
            }
        }
    }


    int r1 = 0, r2 = 0;
    for(int i=1;i<=k;i++){
        int c, l;
        cin >> c >> l;
        for(int u=0;u<30;u++){
            if(l & (1 << u)){
                r1 = adv1[r1][c][u];
                r2 = adv2[r2][c][u];
            }
        }
    }
    r1 -= r2;
    if(r1 < 0) r1 += 10007;
    Mint ans = r1;
    ans /= m;
    cout << ans << "\n";
}
