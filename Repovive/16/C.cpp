#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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
        vector<int> mx(n+1, n);
        vector<set<int>> vs(n+1);
        vector<bool> vis(n+1, false);
        for(int i=1;i<=m;i++){
            int k, c;
            cin >> k >> c;
            set<int> cs;
            for(int j=0;j < k; j++){
                int x;
                cin >> x;
                if(!vis[c]) cs.insert(x);
                else if(vs[c].count(x)) cs.insert(x);
                mx[x] = min(mx[x], c);
            }
            vs[c] = cs;
            vis[c] = true;
        }
        vector<int> qnt(n+1, 0);
        for(int i=1;i<=n;i++) qnt[mx[i]]++;
        Mint ans = 1;
        int allx = 0;
        for(int i=n;i>=1;i--){
            allx += qnt[i];
            if(!vis[i]) ans *= allx;
            else{
                int cur = 0;
                for(auto x : vs[i]){
                    if(mx[x] == i) cur++;
                }
                ans *= cur;
            }
            allx--;
        }
        cout << ans << "\n";
    }
}
