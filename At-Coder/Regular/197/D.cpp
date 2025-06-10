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

const int N = 405; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}

struct CmpBitset {
    bool operator()(const bitset<405>& a,const bitset<405>& b) const {
        if(a.count() != b.count()) return a.count() > b.count();
        else {
            for(int i=0;i<405;i++) if(a[i] != b[i]) return a[i];
            return false;
        }
    }
};

bitset<405> bs[405];
bitset<405> cmp[405];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        map<bitset<405>, vector<int>, CmpBitset> mp;
        int n;
        cin >> n;
        bool ok = true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x;
                cin >> x;
                bs[i][j] = x;
                if(i == 1 && bs[i][j] == 0) ok = false;
            }
        }
        if(!ok){
            cout << "0\n";
            for(int i=1;i<=n;i++) bs[i].reset();
            continue;
        }
        for(int i=1;i<=n;i++){
            mp[bs[i]].push_back(i);
        }
        Mint ans = 1;
        for(auto &[k, v] : mp){
            int sz;
            if(v[0] == 1){
                sz = v.size() - 1;
            }else{
                sz = v.size();
            }
            ans *= fat[sz];
        }
        //check if it's indeed a tree.
        vector<bitset<405>> vx(1);
        for(auto &[k, v] : mp) vx.push_back(k);
        
        int cnt = mp.size();
        vector<vector<int>> adj(cnt+1);
        vector<int> h(cnt+1), par(cnt+1);
        assert(vx.size() == cnt + 1);
        for(int i=2;i<=cnt;i++){
            for(int j=i-1;j>=1;j--){
                if((vx[i] & vx[j]) == vx[i]){
                    adj[j].push_back(i);
                    par[i] = j;
                    break;
                }
            }
            assert((vx[i] & vx[1]) == vx[i]);
        }
        map<int, int> inc;
        map<int, int> inv; //some node of this component, act
        for(int i=1;i<=n;i++){
            for(int j=1;j<=cnt;j++){
                if(vx[j] == bs[i]){
                    cmp[j][i] = 1;
                    inc[i] = j;
                    inv[j] = i;
                    break;
                }
            }
        }
        for(int i=1;i<=cnt;i++){
            for(auto &j : adj[i]){
                cmp[j] |= cmp[i];
            }
        }
        //tree is made, now check for each pair i, j if (bs[i] & bs[j] & bs[lca]) == nodes in
        h[1] = 0;
        for(int i=1;i<=cnt;i++){
            for(auto &x : adj[i]){
                h[x] = h[i] + 1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int a = inc[i], b = inc[j];
                while(h[a] != h[b]){
                    if(h[a] > h[b]) a = par[a];
                    if(h[b] > h[a]) b = par[b];
                }
                while(a != b){
                    a = par[a];
                    b = par[b];
                }
                if(a == inc[j] || a == inc[i]) continue;
                if((bs[i] & bs[j] & bs[inv[a]]) != cmp[a]) ok = false;
            }
        }
        //end check

        if(ok) cout << ans << "\n";
        else cout << "0\n";
        for(int i=1;i<=n;i++){
            bs[i].reset();
            cmp[i].reset();
        }
    }
}
