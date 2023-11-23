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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Mint ans = 0;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        reverse(v.begin(), v.end());
        vector<pair<ll,Mint>> vp1, vp2;
        vp1.push_back({1000005, Mint(1)});
        for(int i=0;i<n;i++){
            vp2.push_back({1000005, Mint(1)});
            Mint cs = n - i;
            Mint cur = 0;
            for(auto [a, c] : vp1){
                auto &[d, f] = vp2.back();
                if(a >= v[i]){
                    if(d == v[i]){
                        f += c;
                    }else{
                         vp2.push_back({v[i], c});
                    }
                }else{
                    ll div = (v[i] - 1)/a + 1;
                    if(d == v[i]/div){
                        ans += (div - 1)*c*cs;
                        f += c;
                    }else{
                        ans += (div - 1) * c * cs;
                        vp2.push_back({v[i]/div, c});
                    }
                }
            }
            vp1 = vp2;
            vp2.clear();
        }
        cout << ans << "\n";
    }
}
