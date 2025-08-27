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
    Mint(int u){ 
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

Mint dp[10], ndp[10];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        if(s[0] == '?' || s[0] == '1') cout << 1 << "\n";
        else cout << "0\n";
        return 0;
    }
    Mint ans = 0;
    //00 //need at least two "11" with even index; or "111" with even index
    //state 0, last was 0
    //state 1, 1 with even index
    //state 2, 11 with even index
    //state 3, has 11 with even index but is now inactive
    //state 4, has 11 with even, and 1 with odd
    //state 5, has 111 or 11 11 with even
    if(s[0] != '1' && s.back() != '1'){
        auto cs = s;
        cs[0] = '0';
        cs.back() = '0';
        for(int j=0;j<=4;j++) dp[j] = ndp[j] = 0;
        dp[0] = 1;
        for(int i=0;i<n;i++){
            ndp[0] = ndp[1] = ndp[2] = ndp[3] = ndp[4] = 0;
            if(cs[i] != '0'){
                if(i % 2 == 1){
                    // ndp[5] += dp[2] + dp[5] + dp[4];
                    // ndp[4] += dp[3];
                    ndp[4] += dp[3] + dp[4]; //odd even --finish
                    ndp[1] += dp[0]; //even odd -- begin
                    ndp[2] += dp[2]; //can't begin
                }else{
                    // ndp[5] += dp[5];
                    ndp[3] += dp[1] + dp[2]; //odd even -- begin
                    ndp[0] += dp[0]; //cant begin
                    ndp[4] += dp[4];
                }
            }   
            if(cs[i] != '1'){
                ndp[0] += dp[0] + dp[1];
                ndp[2] += dp[3] + dp[2];
                ndp[4] += dp[4];
            }
            dp[0] = ndp[0], dp[1] = ndp[1], dp[2] = ndp[2], dp[3] = ndp[3], dp[4] = ndp[4];
        }
        ans += dp[4];
    }
    // cout << "after 00 " << ans << "\n";

    //01 //need some "11" with odd index;
    if(s[0] != '1' && s.back() != '0'){
        auto cs = s;
        cs[0] = '0';
        cs.back() = '1';
        reverse(cs.begin(), cs.end());
        for(int j=0;j<=5;j++) dp[j] = ndp[j] = 0;
        dp[0] = 1;
        for(int i=0;i<n;i++){
            ndp[0] = ndp[1] = ndp[2] = 0;
            if(cs[i] != '0'){
                ndp[2] += dp[2];
                if(i % 2 == 0) ndp[1] += dp[0];
                else ndp[2] += dp[1], ndp[0] += dp[0];
            }   
            if(cs[i] != '1'){
                ndp[0] += dp[0] + dp[1];
                ndp[2] += dp[2];
            }
            dp[0] = ndp[0], dp[1] = ndp[1], dp[2] = ndp[2];
        }
        ans += dp[2];
    }
    // cout << "after 01 " << ans << "\n";
    //10 //need some "11" with odd index;
    if(s[0] != '0'&& s.back() != '1'){
        auto cs = s;
        cs[0] = '1';
        cs.back() = '0';
        for(int j=0;j<=5;j++) dp[j] = ndp[j] = 0;
        dp[0] = 1;
        for(int i=0;i<n;i++){
            ndp[0] = ndp[1] = ndp[2] = 0;
            if(cs[i] != '0'){
                ndp[2] += dp[2];
                if(i % 2 == 0) {
                    ndp[1] += dp[0];
                }else{
                    ndp[2] += dp[1], ndp[0] += dp[0];
                }
            }   
            if(cs[i] != '1'){
                ndp[0] += dp[0] + dp[1];
                ndp[2] += dp[2];
            }
            dp[0] = ndp[0], dp[1] = ndp[1], dp[2] = ndp[2];
        }
        ans += dp[2];
    }
    // cout << "after 10 " << ans << "\n";
    //11 //done;
    if(s[0] != '0' && s.back() != '0'){
        Mint cur = 1;
        for(int i=1;i<n-1;i++){
            if(s[i] == '?') cur *= 2;
        }
        ans += cur;
    }
    // cout << "after 11 " << ans << "\n";

    cout << ans << "\n";
}
