#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int m, dd;

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

Mint dp[2005][2][2005];
int pt[2005];

bool check(string a){
    for(int i=0;i<a.size();i++){
        if(!(i % 2) && a[i] == ('0' + dd)) return false;
        if(i % 2 && a[i] != ('0' + dd)) return false;
    }
    reverse(a.begin(), a.end());
    int cg = 0, aux = 1;
    for(int i=0;i<a.size();i++){
        int dg = a[i] - '0';
        cg = (cg + aux*dg)%m;
        aux = (aux * 10) % m;
    }
    if(cg) return false;
    else return true;
}

void cpt(int n){
    pt[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        pt[i] = (pt[i+1] * 10) % m;
    }
}

Mint calcdp(string s){
    int n = s.size();
    memset(dp, 0, sizeof(dp));
    dp[n][0][0] = dp[n][1][0] = 1;
    for(int i=n-1;i>=0;i--){
        for(int k=0;k<m;k++){
            for(int d=0;d<=s[i]-'0';d++){
                if(!(i%2) && d == dd) continue;
                if(i%2 && d != dd) continue;
                if(!i && d == 0) continue;
                if(d == s[i] - '0') dp[i][1][(d*pt[i]+k)%m] += dp[i+1][1][k];
                else dp[i][1][(d*pt[i]+k)%m] += dp[i+1][0][k];
            }   
            for(int d=0;d<=9;d++){
                if(!(i%2) && d == dd) continue;
                if(i%2 && d != dd) continue;
                if(!i && d == 0) continue;
                dp[i][0][(d*pt[i]+k)%m] += dp[i+1][0][k];
            }
        }
    }
    return dp[0][1][0];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> m >> dd;
    string a, b;
    cin >> a >> b;  
    cpt(a.size());
    Mint ans = calcdp(b);
    ans -= calcdp(a);
    if(check(a)) ans+=1;
    cout << ans << "\n";
    //cout << calcdp(b) << " " << calcdp(a) << "\n";
}   
