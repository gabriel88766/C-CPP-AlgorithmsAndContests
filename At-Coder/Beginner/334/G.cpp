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

const int N = 1e6+5;   
int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}
Mint sum = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> adj[N];
int dfs_num[N], dfs_low[N];
int cnt;


void dfs(int u, int p = -1) {
    dfs_num[u] = dfs_low[u] = ++cnt;
    int ch = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (dfs_num[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        } else {
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if (dfs_low[v] >= dfs_num[u] && p != -1) sum += 1; //is articulation point
            ++ch;
        }
    }
    if(p == -1 && ch > 1) // is articulation point
        sum += ch - 1;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void find_cutpoints(int n) {
    vector<int> permutation;
    for(int i=1;i<=n;i++) permutation.push_back(i);
    shuffle(permutation.begin(), permutation.end(), rng);
    for (auto i : permutation) {
        if (!dfs_num[i])
            dfs(i);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<vector<char>> gr(n, vector<char>(m));
    int cnt = 0;
    init();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> gr[i][j];
            if(gr[i][j] == '#') cnt++;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gr[i][j] == '#'){
                int c1 = m*i + j + 1;
                for(int k=0;k<4;k++){
                    int di = i + dx[k];
                    int dj = j + dy[k];
                    if(di < 0 || di >= n) continue;
                    if(dj < 0 || dj >= m) continue;
                    if(gr[di][dj] != '#') continue;
                    int c2 = m*di + dj + 1;
                    adj[c1].push_back(c2);
                    unite(c1, c2);
                }
            }
        }
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gr[i][j] == '#'){
                v.push_back(get(m*i+j+1));
            }
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int ttc = v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gr[i][j] == '#'){
                if(sz[get(m*i+j+1)] == 1){
                    sum += ttc - 1;
                }else sum += ttc;
            }
        }
    }
    find_cutpoints(n*m);
    cout << sum/cnt << "\n";
}
