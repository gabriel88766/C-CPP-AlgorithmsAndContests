#include <bits/stdc++.h>

using namespace std;
const int N  = 2e5+3;
set<int> v[N];
vector<int> adj[N];
int ans[N], tab[N];
int n;

void dfs(int u,int p){
    for(auto x: adj[u]){
        if(x != p) dfs(x, u);
    }
    ans[u] = v[tab[u]].size();
    if(p){
        if(v[tab[u]].size() > v[tab[p]].size()){
            for(auto x : v[tab[p]]){
                v[tab[u]].insert(x);
            }
            v[tab[p]].clear();
            tab[p] = tab[u];
        }else{
            for(auto x : v[tab[u]]){
                v[tab[p]].insert(x);
            }
            v[tab[u]].clear();
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int aux;
        cin  >> aux;
        v[i].insert(aux);
        tab[i] = i;
    }
    for(int i=2;i<=n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}
