#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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
int cnt = 0;

void kruskal(){
    sort(edges.begin(), edges.end());
    init();
    int bp = 0, ep=0;
    for(int i=0;i<edges.size();i++){
        ep = i;
        if(i+1 < edges.size() && edges[i+1].w == edges[i].w) continue;
        int pad = 0, add = 0;
        for(int j=bp;j<=ep;j++){
            if(get(edges[j].a) != get(edges[j].b)) pad++;
        }
        for(int j=bp; j<=ep;j++){
            if(get(edges[j].a) != get(edges[j].b)){
                unite(edges[j].a, edges[j].b);
                add++;
            }
        }
        cnt += (pad - add);
        bp = i+1;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges.push_back({a,b,w});
    }
    kruskal();
    cout << cnt;
}
