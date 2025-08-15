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

const int N = 2e5+2; //O(N) preprocessing, O(1) query

// //Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        Mint ans = 2;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //check bipartite
        vector<int> tg(n+1, -1);
        queue<int> q;
        q.push(1);
        tg[1] = 0;
        bool ok = true;
        while(q.size()){
            auto u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(tg[v] == -1){
                    tg[v] = tg[u] ^ 1;
                    q.push(v);
                }else if(tg[v] != (tg[u] ^ 1)){
                    ok = false;
                }
            }
        }
        if(!ok){
            ans = 0;
        }else if(m != n-1){
            ans = 0; //there is a cycle
        }else if(n != 2){
            vector<int> nlv;
            vector<bool> isnl(n+1);
            for(int i=1;i<=n;i++){
                if(adj[i].size() != 1){
                    nlv.push_back(i);
                    isnl[i] = true;
                }
            }
            for(auto u : nlv){
                int cnt = 0;
                for(auto v : adj[u]){
                    if(isnl[v]) cnt++;
                }
                ans *= fat[adj[u].size() - cnt];
                if(cnt > 2) ok = false;
            }
            if(!ok) ans = 0;
            if(nlv.size() > 1) ans *= 2;
        }
        cout << ans << "\n";
    }
}
