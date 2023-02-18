//Find Diameter
const int N = 2e5+3;
vector<int> adj[N];
int d[N], n;

void bfs(int src){
    queue<int> q;
    q.push(src); 
    d[src] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : adj[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1; q.push(v);
            }
        }
    }
}

pair<int,int> diameter(){ //node first to second is the diameter.
    memset(d, 63, sizeof(d));
    bfs(1);
    int fart1 = 1, maxd = 0, fart2 = 1;
    for(int i=2;i<=n;i++) if(d[i] > maxd) maxd = d[i], fart1 = i;
    memset(d, 63, sizeof(d));
    bfs(fart1);
    maxd = 0;
    for(int i=1;i<=n;i++) if(d[i] > maxd) maxd = d[i], fart2 = i;
    return {fart1, fart2};
}