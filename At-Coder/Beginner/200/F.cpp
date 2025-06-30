#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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

Mint dp1[2][2], dp2[2][2];
Mint ndp1[2][2], ndp2[2][2];

Mint ans1[2][2], ans2[2][2];


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    ll k;
    cin >> s >> k;
    if(s[0] != '?'){
        dp1[s[0]-'0'][s[0]-'0'] += 1;
    }else{
        dp1[1][1] += 1;
        dp1[0][0] += 1;
    }
    for(int i=1;i<s.size();i++){
        for(int u=0;u<2;u++){
            for(int v=0;v<2;v++){
                ndp1[u][v] = 0;
                ndp2[u][v] = 0;
            }
        }
        for(int u=0;u<2;u++){
            for(int v=0;v<2;v++){
                for(int nn=0;nn<2;nn++){
                    if(s[i] != '?' && s[i] - '0' != nn) continue;
                    if(nn == u || nn == v){
                        ndp1[u][nn] += dp1[u][v];
                        ndp2[u][nn] += dp2[u][v];
                    }else{
                        assert(u == v);
                        ndp1[u][nn] += dp1[u][v];
                        ndp2[v][nn] += dp2[u][v] + dp1[u][v];
                    }
                }
            }
        }
        for(int u=0;u<2;u++){
            for(int v=0;v<2;v++){
                dp1[u][v] = ndp1[u][v];
                dp2[u][v] = ndp2[u][v];
            }
        }
    }
    bool flag = false;
    while(k){
        if(k & 1){
            if(!flag){
                for(int u=0;u<2;u++){
                    for(int v=0;v<2;v++){
                        ans1[u][v] = dp1[u][v];
                        ans2[u][v] = dp2[u][v];
                    }
                }
                flag = true;
            }else{
                for(int u=0;u<2;u++){
                    for(int v=0;v<2;v++){
                        ndp1[u][v] = 0;
                        ndp2[u][v] = 0;
                    }
                }
                for(int i=0;i<2;i++){
                    for(int j=0;j<2;j++){
                        for(int u=0;u<2;u++){
                            for(int v=0;v<2;v++){
                                if(i != j && u != v && j == u){
                                    ndp1[i][v] += ans1[i][j] * dp1[u][v];
                                    ndp2[i][v] += ans1[i][j] * dp2[u][v] + ans2[i][j] * dp1[u][v] - ans1[i][j] * dp1[u][v];
                                }else if(i != j || u != v || i == u){
                                    ndp1[i][v] += ans1[i][j] * dp1[u][v];
                                    ndp2[i][v] += ans1[i][j] * dp2[u][v] + ans2[i][j] * dp1[u][v];
                                }else{
                                    ndp1[i][v] += ans1[i][j] * dp1[u][v];
                                    ndp2[i][v] += ans1[i][j] * dp2[u][v] + ans2[i][j] * dp1[u][v] + ans1[i][j] * dp1[u][v];
                                }
                            }
                        }       
                    }
                }
                for(int u=0;u<2;u++){
                    for(int v=0;v<2;v++){
                        ans1[u][v] = ndp1[u][v];
                        ans2[u][v] = ndp2[u][v];
                    }
                }
            }
        }
        k >>= 1;
        for(int u=0;u<2;u++){
            for(int v=0;v<2;v++){
                ndp1[u][v] = 0;
                ndp2[u][v] = 0;
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int u=0;u<2;u++){
                    for(int v=0;v<2;v++){
                        if(i != j && u != v && j == u){
                            ndp1[i][v] += dp1[i][j] * dp1[u][v];
                            ndp2[i][v] +=  dp1[i][j] * dp2[u][v] + dp2[i][j] * dp1[u][v] - dp1[i][j] * dp1[u][v];
                        }else if(i != j || u != v || i == u){
                            ndp1[i][v] += dp1[i][j] * dp1[u][v];
                            ndp2[i][v] += dp1[i][j] * dp2[u][v] + dp2[i][j] * dp1[u][v];
                        }else{
                            ndp1[i][v] += dp1[i][j] * dp1[u][v];
                            ndp2[i][v] += dp1[i][j] * dp2[u][v] + dp2[i][j] * dp1[u][v] + dp1[i][j] * dp1[u][v];
                        }
                    }
                }       
            }
        }
        for(int u=0;u<2;u++){
            for(int v=0;v<2;v++){
                dp1[u][v] = ndp1[u][v];
                dp2[u][v] = ndp2[u][v];
            }
        }
    }
    
    cout << ans2[0][0] + ans2[0][1] + ans2[1][0] + ans2[1][1] << "\n";
}
