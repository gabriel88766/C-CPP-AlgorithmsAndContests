#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
int p[N], sz[N];
bool cmp[N];

pair<int,int> par[N];
int h[N];

void init(){
    for(int i=1;i<N;i++){ p[i] = i, sz[i] = 1;}
}

int get(int a){
    return p[a] = (p[a] == a ? a : get(p[a]));
}

int cur;
void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
}

vector<int> adj[N], adjm[N];

void dfs(int u, int pc){
    h[u] = h[pc] + 1;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        int f = adjm[u][i];
        if(v != pc){
            dfs(v, u);
            par[v] = {u, f};
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        int x;
        cin >> x;
        for(int j=2;j<=k;j++){
            int y;
            cin >> y;
            if(get(x) != get(y)){
                unite(x, y);
                adj[x].push_back(y);
                adjm[x].push_back(i);
                adj[y].push_back(x);
                adjm[y].push_back(i);
            }
        }
    }
    h[0] = -1;
    for(int i=1;i<=m;i++){
        int rt = get(i);
        if(!cmp[rt]){
            cmp[rt] = true;
            dfs(rt, 0);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        if(get(u) == get(v)){
            vector<int> ans = {u}, aux;
            while(h[u] != 0){
                ans.push_back(par[u].second);
                u = par[u].first;
                ans.push_back(u);
            }
            while(h[v] != 0){
                aux.push_back(v);
                aux.push_back(par[v].second);
                v = par[v].first;
            }
            reverse(aux.begin(), aux.end());
            for(auto x : aux) ans.push_back(x);
            cout << (ans.size() + 1)/2 << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else cout << "-1\n";
    }
}