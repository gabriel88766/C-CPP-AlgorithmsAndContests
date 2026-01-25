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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, c;
        cin >> n >> c;  
        string s;
        cin >> s;
        s = " " + s;
        Mint ans = 1;
        vector<int> vx;
        for(int i=1;i<n;i++){
            int cur = -1;
            if(s[i] == '1'){
                cur = 2;
            }else if(s[i] == '0'){
                cur = (i+1 - 2);
            }else{
                if(i+1 - 2 == 0){
                    cur = 2;
                }else if(i + 1 - 2 == 1){
                    cur = 1;
                }else{
                    vx.push_back(i+1-2);
                }
            }
            if(cur == -1) continue;
            if(cur != 0 && gcd(c, cur) != 1){
                c /= gcd(c, cur);
            }else if(cur == 0) c = 1;
            ans *= cur;
        }
        if(s[n] == '0') c = 1;
        if(c == 1) cout << "-1\n";
        else{
            if(vx.size()){
                if(__builtin_popcountll(c) != 1){
                    for(auto x : vx) ans *= 2;
                }else{
                    //2^k;
                    int cnt = 0;
                    int mx = __builtin_ctz(c);
                    vector<int> v2;
                    for(auto x : vx){
                        if(x % 2 == 0){
                            cnt++;
                            ans *= 2;
                        }else{
                            v2.push_back(x);
                        }
                    }
                    if(cnt < mx){
                        mx -= cnt;
                        while(mx > 1 && v2.size()){
                            ans *= 2;
                            v2.pop_back();
                            mx--;
                        }
                        for(auto x : v2) ans *= x;
                    }else c = 1; //cnt >= mx;               
                }
            }
            if(c != 1) cout << ans << "\n";
            else cout << "-1\n";
        }
    }
}
