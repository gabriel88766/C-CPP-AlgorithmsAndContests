const int N = 5005;

struct Edge{
    ll u, v, w;
};
vector<Edge> edges;
ll dist[N];
int par[N];

void bellman(int n){
    memset(dist, 63, sizeof(dist));
    dist[1] = 0;
    for(int i=0;i<n;i++)
        for(auto edge : edges){
            if(dist[edge.u] == INF_LL) continue;
            if(dist[edge.v] > dist[edge.u] + edge.w){
                dist[edge.v] = dist[edge.u] + edge.w;
                par[edge.v] = edge.u;
            }   
        }
}

vector<int> cycle;
bool negative_cycle_bellman(int n){
    int cur, x = -1;
    for(int i=0;i<=n;i++){
        x=-1; //if x changed in last iteration, thus x belongs to  a negative cycle.
        for(auto edge : edges){
            if(dist[edge.v] > dist[edge.u] + edge.w){
                dist[edge.v] = dist[edge.u] + edge.w;
                par[edge.v] = edge.u;
                x = edge.v;
            }   
        }
    }
    if(x == -1) return false;
    for(int i=0;i<=n;i++) x = par[x];
    cur = x;
    do{
        cycle.push_back(cur);
        cur = par[cur]; 
    }while(cur != x);
    cycle.push_back(cur);
    reverse(cycle.begin(), cycle.end());
    return true;
}