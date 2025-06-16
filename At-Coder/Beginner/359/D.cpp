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

Mint dp[512], ndp[512];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    //find all possibilities for the first k-1 letters.
    for(int i=0;i<1 <<(k-1);i++){
        bool cok = true;
        for(int j=0;j<k-1;j++){
            if(s[k-j-2] == '?') continue;
            if(i & (1 << j)){
                if(s[k-j-2] == 'A') cok = false;
            }else{
                if(s[k-j-2] == 'B') cok = false;
            }
        }
        if(cok) dp[i] = 1;
        

    }
    int msk = 0;
    for(int i=0;i<k-2;i++) msk |= (1 << i);
    for(int i=k-1;i<n;i++){
        for(int u=0;u<1 << (k-1); u++) ndp[u] = 0;
        for(int u=0;u<1 << (k-1); u++){
            string cur;
            for(int j=0;j<(k-1);j++){
                if(u & (1 << j)) cur += 'B';
                else cur += 'A';
            }
            reverse(cur.begin(), cur.end());
            // if(dp[u].v != 0) cout << u << " " << cur << " " << ((u & msk)) << " - "; 
            if(s[i] == '?'){
                cur += 'A';
                auto rev = cur;
                reverse(rev.begin(), rev.end());
                if(cur != rev){
                    ndp[((u & msk) << 1)] += dp[u];
                }
                cur.pop_back();
                cur += 'B';
                rev = cur;
                reverse(rev.begin(), rev.end());
                assert(cur.size() == k);
                if(cur != rev){
                    ndp[((u & msk) << 1) + 1] += dp[u];
                }
            }else{
                cur += s[i];
                auto rev = cur;
                reverse(rev.begin(), rev.end());
                if(cur != rev){
                    ndp[((u & msk) << 1) + (s[i]-'A')] += dp[u];
                }
            }
        }

        for(int u=0;u<1 << (k-1); u++) dp[u] = ndp[u];
    }
    Mint ans = 0;
    for(int u=0;u<1 << (k-1); u++) ans += dp[u];
    cout << ans << "\n";
}
