#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];   
int p[N], sz[N], c[N], maxqt[N];
ll cursum[N], ans[N];
set<pair<int,int>> sp[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1; maxqt[i] = 1; cursum[i] = c[i]; sp[i].insert({c[i], 1});}
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
    for(auto x : sp[b]){
        auto it = sp[a].lower_bound({x.first, 0});
        auto val = x;
        if(it != sp[a].end() && it->first == x.first){
            val.second += it->second;
            sp[a].erase(it); 
        }
        sp[a].insert(val);
        if(val.second > maxqt[a]){
            maxqt[a] = val.second;
            cursum[a] = val.first;
        }else if(val.second == maxqt[a]){
            cursum[a] += val.first;
        }
    }
}

void dfs(int u, int p = -1){
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            unite(u, v);
        }
    }
    ans[u] = cursum[get(u)];
}

int n;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init();
    dfs(1);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}
