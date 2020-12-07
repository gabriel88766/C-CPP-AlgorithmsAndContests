#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+3;
const int INF = 0x3f3f3f3f;
int n,farthest;
vector<int> adj[N];
int d[N];

void bfs(int rt=1,int mode=1){

    for(int i=0;i<N;i++) d[i]=INF;

    queue<int> q;
    q.push(rt);
    d[rt] = 0;

    while (!q.empty()) {
      int u = q.front(); q.pop();
        for (int v : adj[u]) if (d[v] == INF)
          d[v] = d[u]+1, q.push(v);
       if(q.empty() && mode) farthest = u;
    }
}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
cin >> n;
for(int i=1;i<n;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
bfs();
bfs(farthest);
cout << d[farthest];


}
