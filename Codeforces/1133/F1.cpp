#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N  = 2e5+3;

vector<int> adj[N];
vector<pair<int,int>> edges;

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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        edges.emplace_back(a,b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    init();
    int maxi, maxv = 0;
    for(int i=1;i<=n;i++){
        if(adj[i].size() > maxv){
            maxv = adj[i].size();
            maxi = i;
        }
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<adj[maxi].size();i++){
        ans.emplace_back(maxi, adj[maxi][i]);
        unite(maxi, adj[maxi][i]);
    }
    for(auto e : edges){
        if(get(e.first) != get(e.second)){
            ans.emplace_back(e.first, e.second);
            unite(e.first,e.second);
        }
    }
    for(auto u : ans) cout << u.first << " " << u.second << "\n";
}   
