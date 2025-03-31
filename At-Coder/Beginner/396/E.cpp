#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
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

int vis[N];
vector<int> adj[N], adjw[N];
int val[N], ans[N];
vector<pair<int, int>> cur;
vector<vector<pair<int, int>>> av;
void dfs(int u){
    cur.push_back({val[u], u});
    vis[u] = true;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i], w = adjw[u][i];
        if(!vis[v]){
            val[v] = val[u] ^ w;
            dfs(v);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> chk;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(get(a) == get(b)) chk.push_back({a, b, c});
        else{
            unite(a, b);
            adj[a].push_back(b);
            adjw[a].push_back(c);
            adj[b].push_back(a);
            adjw[b].push_back(c);
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            val[i] = 0;
            dfs(i);
            av.push_back(cur);
            cur.clear();
        }
    }
    bool ok = true;
    for(auto &[a, b, c] : chk){
        if((val[a] ^ val[b]) != c) ok = false;
    }
    if(ok){
        for(auto &v : av){
            vector<int> cnt(30);
            for(auto &[x, y] : v){
                for(int b=0;b<30;b++){
                    if(x & (1 << b)){
                        cnt[b]++;
                    }
                }
            }
            int sz = v.size();
            int msk = 0;
            for(int b=0;b<30;b++){
                if(cnt[b] > sz - cnt[b]) msk ^= (1 << b);
            }
            for(auto &[x, y] : v){
                ans[y] = x ^ msk;
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }else cout << "-1\n";
}
