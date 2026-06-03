#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 676767677; //1e9+7
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> idx(m);
        vector<int> v(n+1);
        vector<int> tt(m);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            idx[v[i]].push_back(i);
        }
        Mint ans = 1;
        for(int i=0;i<m;i++){
            tt[i] = idx[i].size();
            if(i == 0) continue;
            tt[i] += tt[i-1];
            for(auto j : idx[i]){
                int bg = INF_INT;
                if(j - 1 >= 1 && v[j] > v[j-1]) bg = min(bg, v[j-1]);
                if(j + 1 <= n && v[j] > v[j+1]) bg = min(bg, v[j+1]);
                if(bg == v[j] - 1){
                    ans *= tt[v[j]-1];
                }else if(bg != INF_INT){
                    ans *= (tt[v[j]-1] - tt[v[j]-2]);
                }else{
                    ans = 0;
                }
            }
        }
        cout << ans << "\n";
    }
}
