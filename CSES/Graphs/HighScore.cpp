#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 5005;
 
struct Edge{
    ll u, v, w;
};
vector<Edge> edges;
vector<int> invadj[N];
vector<int> listv;
bool vis[N];
ll dist[N];
 
void bellman(int n){ // true if not inf cycle
    ll neginf;
    memset(dist, 192, sizeof(dist));
    memset(&neginf, 192, sizeof(ll));
    dist[1] = 0;
    for(int i=0;i<=n;i++)
        for(auto edge : edges){
            if(dist[edge.u] == neginf) continue;
            if(dist[edge.v] < dist[edge.u] + edge.w){
                dist[edge.v] = dist[edge.u] + edge.w;
                if(i == n) listv.push_back(edge.v);
            }   
        }
}

void dfs(int u){
    vis[u] = true;
    for(auto x : invadj[u]) if(!vis[x]) dfs(x);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin >>a >> b >> w;
        edges.push_back({a,b,w});
        invadj[b].push_back(a);
    }
    bellman(n);
    dfs(n);
    bool ok = true;
    for(auto x : listv){
        if(vis[x]) ok = false;
    }
    if(ok) cout << dist[n];
    else cout << "-1";
}