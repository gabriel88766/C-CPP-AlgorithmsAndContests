
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+3, M = 20;
int h[N], anc[M][N], n, m;
int vp[N], ans[N];

vector<int> adj[N];

void dfs(int u, int p){
    anc[0][u] = p;
    if(u != 1) h[u] = h[p]+1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v,u);
        }
    }
}

void dfs2(int u, int p){

    for(auto v : adj[u]){
        if(v != p){
            dfs2(v,u);
        }
    }
    ans[u] += vp[u];
    ans[p] += ans[u];
}

void build(){
    h[1]=0;
    dfs(1,0);
    for(int i=1;i<M;i++){
        for(int j=1;j<=n;j++){
            anc[i][j] = anc[i-1][anc[i-1][j]];
        }
    }
}

int lca(int u,int v){
    if(h[u]<h[v]) swap(u,v);
    for(int i = M-1 ; i>=0 ; i--){
        if((h[u]-(1<<i)) >= h[v] ){
            u = anc[i][u];
        }
    }
    if(u == v) return u;
    for(int i = M-1 ; i>=0 ; i--){
        if( anc[i][u] != anc[i][v] ){
            u = anc[i][u], v = anc[i][v];
        }
    }
    return anc[0][u];

}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build();

    for(int i=0; i<m; i++){
        int a,b,aux;
        cin >> a >> b;
        vp[a]++;
        vp[b]++;
        aux = lca(a,b);
        vp[aux] --;
        vp[anc[0][aux]] --;
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        cout << ans[i] << " \n";
    }
}
