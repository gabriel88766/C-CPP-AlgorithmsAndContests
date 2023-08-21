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

Mint dp[5005][5005], tt[5005];

int cnt[5005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int ml= 0;
        for(int i=1;i<=n;i++) cnt[i] = 0;
        for(int i=1;i<=n;i++){
            cnt[v[i]]++;
            if(cnt[v[i]] == k){
                for(int j=1;j<=n;j++) cnt[j] = 0;
                ml += k;
            }
        }

        tt[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                Mint oldv = dp[v[i]][j+1];
                if(j % k){
                    dp[v[i]][j+1] += dp[v[i]][j];
                }else{
                    dp[v[i]][j+1] += tt[j];
                }
                if((j+1) % k == 0) tt[j+1] += (dp[v[i]][j+1]-oldv);
            }
        }

        cout << tt[ml] << "\n";
        for(int i=0; i <= n;i++) {
            for(int j=0;j<=n;j++) { 
                dp[i][j] = 0;
            } 
            tt[i] = 0;
        }
        
        
    }
}
