//O(V+E)
const int N = 2e5+3;
int d[N], p[N];
vector<int> adj[N];

void bfs(int src){
    memset(d, 63, sizeof(d)); //this line must be skipped if multiples bfs
    queue<int> q;
    q.push(src); 
    d[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
}

//to find path
cur = dest;
vector<int> ans;
while(cur != src){
    ans.push_back(cur);
    cur = p[cur];
}
ans.push_back(src);
reverse(ans.begin(), ans.end());