#include <bits/stdc++.h>

using namespace std;



const int N = 1e5+3;
const int INF = 0x3f3f3f3f;
char hasAnswer = true;

int d[N];


vector<int> adj[N];
queue<int> q;

void bfs(){
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : adj[u])
        if (d[v] == INF) d[v] = ((d[u]+1)&1), q.push(v);
        else if(d[v] == d[u]) {
            hasAnswer = false;
        }
    }
}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int n,m,beginv=1,a,b,cont=0,curp;
memset(d, INF, sizeof(d));
vector<int> A,B;
cin >> n >> m;
for(int i=0;i<m;i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
while(true){
    while((adj[beginv].size()==0 || (d[beginv]!=INF)) && beginv<=n) beginv++;

    if(beginv > n) break;
    q.push(beginv);
    d[beginv] = 0;
    bfs();
    if(!hasAnswer) break;

}

if(hasAnswer){
    for(int i=1;i<=n;i++){
        if(d[i]==0) A.push_back(i);
        if(d[i]==1) B.push_back(i);
    }
    cout << A.size() << endl;
    for(int i=0;i<A.size();i++){
        cout << A[i] << " ";
    }
    cout << endl;
    cout << B.size() << endl;
    for(int i=0;i<B.size();i++){
        cout << B[i] << " ";
    }
}else cout << -1;
}

