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

struct Aho{ //declare once! too much memory
    int len;
    vector<vector<int>> trie;
    vector<int> slink;
    vector<int> val;
    vector<int> qnt;
    int c = 0;
    void add(const string &s, int msk){
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
            if(trie[cur][s[i]-'a']) cur = trie[cur][s[i]-'a'];
            else cur = trie[cur][s[i]-'a'] = ++c;
        }
        val[cur] = msk;
        qnt[cur]++;
    }
    int get(const string &s){
        int cur = 0;
        for(int i = 0; i < s.size(); i++) cur = trie[cur][s[i]-'a'];
        return cur;
    }
    void addLink(){
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0;i<26;i++){
                if(trie[u][i]){
                    q.push(trie[u][i]);
                    if(u){
                        int v = slink[u];
                        while(v && !trie[v][i]) v = slink[v];
                        slink[trie[u][i]] = trie[v][i];
                        qnt[trie[u][i]] += qnt[trie[v][i]];
                    }
                }
            }
        }
    }
    Aho(vector<string> &v, int maxlen){
        len = maxlen;
        val = vector<int>(maxlen, false);
        trie = vector<vector<int>>(maxlen, vector<int>(26, 0));
        slink = vector<int>(maxlen, 0);
        qnt = vector<int>(maxlen, 0);
        for(int i=0;i<v.size();i++) add(v[i], 1 << i);
        addLink();
    }
    int dfs(int x){
        if(slink[x] != 0) return val[x] | dfs(slink[x]);
        else return val[x];
    }
    void markAll(){
        for(int i=0;i<=c;i++){
            val[i] = dfs(i);
        }
    }
};

Mint dp[100][256];
Mint ndp[100][256];
int vx[100][26];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, l;
    cin >> n >> l;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    Aho hoho(v, 100);
    hoho.markAll();
    //at most 80 x 2^8 states
    dp[0][0] = 1;   
    int mx = hoho.c;
    for(int j=0;j<=mx;j++){
        for(int k=0;k<26;k++){
            int cur = j;
            while(cur && !hoho.trie[cur][k]) cur = hoho.slink[cur];
            vx[j][k] = cur;
        }
    }



    for(int i=1;i<=l;i++){
        for(int j=0;j<=mx;j++){
            for(int k=0;k<(1 << n);k++){
                ndp[j][k] = 0;
            }
        }
        for(int j=0;j<=mx;j++){
            for(int k=0;k<(1 << n);k++){
                for(int x=0;x<26;x++){
                    int cur = vx[j][x];
                    
                    ndp[hoho.trie[cur][x]][k | hoho.val[hoho.trie[cur][x]]] += dp[j][k];
                }
            }
        }
        for(int j=0;j<=mx;j++){
            for(int k=0;k<(1 << n);k++){
                dp[j][k] = ndp[j][k];
            }
        }
    }
    Mint ans = 0;
    for(int j=0;j<=mx;j++){
        ans += dp[j][(1 << n) - 1];
    }
    cout << ans << "\n";
}
