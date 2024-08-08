#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int c[N], sub[N], cnt[N];
ll ans[N];
int n;
int p[N];
map<int,int> mp[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; }
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(mp[a].size() < mp[b].size()) swap(a,b);
    p[b] = a;
    for(auto [k, v] : mp[b]) mp[a][k] += v;
}

void dfs(int u, int p){
    sub[u] = 1;
    int x = c[u];
    ll cur = 1;
    ll curans = 1;
    ll curct = 0;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
            ll aux = sub[v];
            if(mp[get(v)].count(x)){
                 aux -= mp[get(v)][x];
                 curct += mp[get(v)][x];
            }
            curans += aux * cur;
            cur += aux;
            unite(v, u);
        }
    }
    ll pt = n - sub[u] - cnt[x] + curct;
    curans += cur * pt;
    ans[x] += curans;
    mp[get(u)][x] = sub[u];
    cnt[x] += sub[u] - curct;
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
}
