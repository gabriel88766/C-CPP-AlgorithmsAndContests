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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int k;
        string s;
        cin >> s >> k;   
        string ans = s;
        deque<int> dq;
        bool ls = false;
        for(int i=0;i<s.size();i++){
            if(s[i] == '?'){
                if(i+1 < s.size()){
                    if(s[i+1] == '?') dq.push_back(i);
                    else if(s[i+1] > '6') ans[i] = '1';
                    else dq.push_back(i);
                }else{
                    //fuck!
                    ls = true;
                }
            }
        }
        while(dq.size() > 20){
            ans[dq.front()] = '2';
            dq.pop_front();
        }
        //dq.size() is <= 20, try all possibilities
        int sz = dq.size();
        ll cur = 0;
        for(int i=0;i<(1 << sz);i++){
            if(ls){
                if(i & 1){
                    cur += 9;
                    if(cur >= k) ans.back() = (cur - k + 1) + '0';
                }else{
                    cur += 6;
                    if(cur >= k) ans.back() = (cur - k + 1) + '0';
                }
            }else{
                cur++;
            }
            if(cur >= k){
                for(int j=0;j<dq.size();j++){
                    if((1 << (sz-j-1)) & i) ans[dq[j]] = '1';
                    else ans[dq[j]] = '2';
                }
                break;
            }
        }
        cout << "Case #" << i << ": " << ans << " ";
        ans = " " + ans;
        vector<Mint> dp(ans.size());
        dp[0] = 1;
        for(int i=1;i<ans.size();i++){
            if(i == 1) dp[i] = 1;
            else{
                if(ans[i-1] == '1' || ans[i-1] == '2'){
                    if(ans[i] == '0') dp[i] += dp[i-2];
                    else if(ans[i] <= '6') dp[i] = dp[i-1] + dp[i-2];
                    else if(ans[i-1] == '1') dp[i] = dp[i-1] + dp[i-2];
                    else dp[i] = dp[i-1];
                }else if(ans[i] != '0') dp[i] = dp[i-1];
                else dp[i] = dp[i-2];
            }
        }
        cout << dp[ans.size()-1] << "\n";

        

    }
}
