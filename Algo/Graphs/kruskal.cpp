//Minimum spanning tree using DSU, O(E)
//DSU
const int N = 2e5+3;   
int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

struct Edge{
    int a, b, w;
    bool operator< (Edge v){
        if(w != v.w) return w < v.w;
        else return make_pair(a,b) < make_pair(v.a,v.b);
    }
};

vector<Edge> edges;
vector<int> adj[N];
ll tw = 0;

void kruskal(){
    sort(edges.begin(), edges.end());
    init();
    for(auto e : edges){
        if(get(e.a) != get(e.b)){
            adj[e.a].push_back(e.b);
            adj[e.b].push_back(e.a);
            unite(e.a, e.b);
            tw += e.w;
        }
    }
}