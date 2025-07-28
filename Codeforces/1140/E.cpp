#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


struct Mint{
    int v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
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
    Mint operator*= (Mint u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
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
    //freopen("in", "r", stdin); //test input
    Mint ans = 1;
    int n, k;
    cin >> n >> k;
    vector<int> v1, v2;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(i % 2) v1.push_back(x);
        else v2.push_back(x);
    }
    auto process = [&](vector<int> v){
        int lx = 0;
        Mint d1 = 0, d2 = 1; //d1 any, d2 = x
        for(auto x : v){
            if(x == -1){
                Mint nd2, nd1;
                if(lx == 0){
                    nd1 = d1 * (k-1) + d2;
                    nd2 = 0;
                }else{
                    nd2 = d1 * (k-1);
                    nd1 = d1 * (k-2) + d2;
                }
                d1 = nd1;
                d2 = nd2;
            }else{
                Mint nd2 = 0;
                if(x == lx){
                    nd2 = (k-1) * d1;
                }else if(lx != 0){
                    nd2 = (k-2) * d1 + d2;
                }else{
                    nd2 = (k-1) * d1 + d2;
                }
                d1 = 0;
                d2 = nd2;
                lx = x;
            }
        }
        if(lx == 0) return d1 * k;
        else return (d1 * (k-1) + d2);  
    };
    ans *= process(v1);
    ans *= process(v2);


    cout << ans << "\n";
}
