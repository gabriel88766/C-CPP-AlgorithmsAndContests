#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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

int qnt[61];
int bs[61];
Mint dp[61], ndp[61];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        qnt[x]++;
    }
    for(int i=1;i<=m;i++){
        int tq;
        ll val;
        cin >> tq >> val;
        if(tq == 1){
            qnt[val]++;
        }else if(tq == 2){
            qnt[val]--;
        }else{
            Mint qnt2 = 0;
            for(int j=0;j<=60;j++) dp[j] = 0;
            int x = 0;
            for(int j=59;j>=0;j--){
                if(val & (1LL << j)){
                    bs[x++] = j;
                }
            }
            bs[x] = -1000000;
            for(int j=60;j>=0;j--){
                for(int k = 0;k < qnt[j]; k++){
                    Mint nqnt2 = 0;
                    for(int j=0;j<x;j++) ndp[j] = dp[j]; //if don't change
                    //from qnt0
                    if(j > bs[0]){
                        nqnt2 += 1;
                    }else if(j == bs[0]){
                        ndp[0] += 1;
                    }
                    for(int u=0;u<x;u++){
                        //if change
                        if(j - u - 1 > bs[u+1]){
                            nqnt2 += dp[u];
                        }else if(j - u - 1 == bs[u+1]){
                            ndp[u+1] += dp[u];
                        }
                    }                    
                    nqnt2 += 2*qnt2;
                    for(int j=0;j<x;j++) dp[j] = ndp[j];
                    qnt2 = nqnt2;
                }
            }
            cout << qnt2 + dp[x-1] << "\n";
        }
    }
}