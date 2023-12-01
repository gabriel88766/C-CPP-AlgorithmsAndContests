#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N], adjn[N], grv;
int ans[N];
map<int,int> cnt;
int v[N], ind; 

int p[N], gr1[N], gr2[N];
map<int,int> mp[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; gr1[i] = ind, gr2[i] = 0;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(mp[a].size() < mp[b].size()) swap(a,b);
    for(auto [k, v] : mp[b]){
        mp[a][k] += v;
        if(mp[a][k] >= 2) gr2[a] = max(gr2[a], k);
    }
    gr1[a] = min(gr1[a], gr1[b]);
    while(gr1[a] >= 0 && (cnt[grv[gr1[a]]] - mp[a][grv[gr1[a]]]) <= 1) gr1[a]--;
    p[b] = a;
}

void dfs(int u,int p){
    mp[u][v[u]]++;
    if(gr1[u] >= 0 && (cnt[grv[gr1[u]]] - mp[u][grv[gr1[u]]]) <= 1) gr1[u]--;
    int j = -1;
    for(int i=0;i<adj[u].size();i++){
        auto v = adj[u][i];
        if(v != p){
            dfs(v, u);
            unite(v, u);
        }else j = adjn[u][i];
    }
    if(j != -1){
        int x = get(u);
        if(gr1[x] >= 0) ans[j] = grv[gr1[x]];
        ans[j] = max(ans[j], gr2[x]);
    }

}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjn[a].push_back(i);
        adj[b].push_back(a);
        adjn[b].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin >> v[i];
        cnt[v[i]]++;
        if(cnt[v[i]] == 2){
            grv.push_back(v[i]);
        }
    }
    sort(grv.begin(), grv.end());
    ind = grv.size();
    --ind;
    init();
    dfs(1, 0);
    for(int i=1;i<n;i++) cout << ans[i] << "\n";
}
