#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+3;
const int INF = 0x3f3f3f3f;
int n,farthest[2];
vector<int> adj[N];
int d[2][N];

void bfs(int pos, int rt,int pos2){

    for(int i=0;i<N;i++) d[pos][i]=INF;

    queue<int> q;
    q.push(rt);
    d[pos][rt] = 0;

    while (!q.empty()) {
      int u = q.front(); q.pop();
        for (int v : adj[u]) if (d[pos][v] == INF)
          d[pos][v] = d[pos][u]+1, q.push(v);
       if(q.empty()) farthest[pos2] = u;
    }
}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int diam;
map<int,int> mp;
cin >> n;
for(int i=1;i<n;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
bfs(0,1,0);
bfs(0,farthest[0],1);
bfs(1,farthest[1],0);


for(int i=1;i<=n;i++){
    cout << max(d[0][i],d[1][i]) << " ";
}


}
