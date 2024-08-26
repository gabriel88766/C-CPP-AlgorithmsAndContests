#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
vector<int> adj[N];
int n;

int h[N], ans[N];

int p[N], mv[N];
vector<pair<int,int>> vp[N];
void init(){
    for(int i=1;i<N;i++) {p[i] = i;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(vp[a][0].second < vp[b][0].second) swap(a,b);
    p[b] = a;
    for(auto [qt, vh] : vp[b]){
        int x0 = vp[a][0].second;
        int im = x0 - mv[a];
        int ic = x0 - vh;
        if(ic < vp[a].size()){
            vp[a][ic].first += qt;
        }else{
            vp[a].push_back({qt, vh});
        }
        if(vp[a][ic].first > vp[a][im].first){
            mv[a] = vh;
        }else if(vp[a][ic].first == vp[a][im].first && ic > im){
            mv[a] = vh;
        }
    }
}

void dfs(int u,int p = 0){
    h[u] = h[p] + 1;
    mv[u] = h[u];
    vp[u].push_back({1, h[u]});
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            unite(u, v);
        }
    }
    int x = get(u);
    ans[u] = mv[x] - h[u];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input;
    init();
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    h[0] = -1;
    dfs(1); 
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
}