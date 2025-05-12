#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        bool ok = true;
        int x, y;
        cin >> x >> y;
        map<pair<int, int>, int> mpn; //map of nodes
        vector<vector<int>> adj(2*k+2);//adjacency
        vector<int> sl(2*k+2, 0); //self loop
        int cn = 0; //count nodes
        for(int i=1;i<=k;i++){
            int nx, ny;
            cin >> nx >> ny;
            if(abs(nx-x) + abs(ny-y) != 2) ok = false;
            else{
                if(abs(nx-x) == 2){
                    int md = (nx + x)/2;
                    if(!mpn.count({md, y})) mpn[{md, y}] = ++cn;
                    sl[mpn[{md, y}]]++;
                }else if(abs(ny - y) == 2){
                    int md = (ny + y)/2;
                    if(!mpn.count({x, md})) mpn[{x, md}] = ++cn;
                    sl[mpn[{x, md}]]++;
                }else{
                    int x1 = x, y1 = ny, x2 = nx, y2 = y;
                    if(!mpn.count({x1, y1})) mpn[{x1, y1}] = ++cn;
                    if(!mpn.count({x2, y2})) mpn[{x2, y2}] = ++cn;
                    adj[mpn[{x1, y1}]].push_back(mpn[{x2, y2}]);
                    adj[mpn[{x2, y2}]].push_back(mpn[{x1, y1}]);
                }
            }
            x = nx, y = ny;
        }
        if(ok){
            Mint ans = 1;
            vector<bool> vis(cn+1, false);
            for(int i=1;i<=cn;i++){
                if(!vis[i]){
                    vector<int> curv;
                    function<void(int)> dfs1 = [&](int u){
                        curv.push_back(u);
                        vis[u] = true;
                        for(auto &v : adj[u]){
                            if(!vis[v]){
                                dfs1(v);
                            }
                        }
                    };  
                    dfs1(i);
                    int adc = 0, slc = 0;
                    for(auto &x : curv) slc += sl[x];
                    for(auto &x : curv) adc += adj[x].size();
                    adc /= 2;
                    if(slc + adc > curv.size()) ans = 0;
                    else if(slc + adc == curv.size()){
                        if(slc == 1){
                            //its also a tree, but one of its vertex has self loop
                            //doesn't change the count. NOTHING TODO.
                        }else{
                            //need to find the cycle
                            ans *= 2;
                        }
                    }else{
                        //ITS A TREE!
                        assert(slc == 0);
                        ans *= curv.size();
                    }
                }   
            }
            cout << ans << "\n";
        }else cout << "0\n";
    }
}
