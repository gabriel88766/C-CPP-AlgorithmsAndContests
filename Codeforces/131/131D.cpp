#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int INF = 0x3f3f3f3f;

vector<int> adj[N];
vector<int> cycle;
char flag=true;
int vis[N];
int pred[N];
int ans[N];
int d[N][N];

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            d[i][j] = INF;
        }
    }
}

void recoverpath(int last,int first){
    int beginp = last;
    cycle.push_back(last);
    while(beginp!=first){
        beginp = pred[beginp];
        cycle.push_back(beginp);
    }
}

void dfs1(int u) {
  vis[u]=1;
  for (int v : adj[u]){
    if(vis[v] == 1 && flag && v!=pred[u]){
        recoverpath(u,v);
        flag = false;
    }
    if (!vis[v] && flag){
       pred[v] = u;
       dfs1(v);
    }
  }
  vis[u] = 2;
}

void bfs(int u){
    queue<int> q;
    int src = u;
    q.push(u);
    d[u][u] = 0;

    while (!q.empty()) {
      int cont = 0;
      int u = q.front(); q.pop();
      for (int v : adj[u]){
          if (d[src][v] == INF){
            d[src][v] = d[src][u]+1, q.push(v),cont++;
          }
      }
    }
}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
init();
int n,a,b;
cin >> n;
for(int i=0;i<n;i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
dfs1(1);
for(int i=0;i<cycle.size();i++){
    bfs(cycle[i]);
}
for(int j=1;j<=n;j++){
    int minimum = INF;
    for(int i=0;i<cycle.size();i++){
        minimum = min(minimum,d[cycle[i]][j]);
    }
    cout << minimum << " ";
}


}
