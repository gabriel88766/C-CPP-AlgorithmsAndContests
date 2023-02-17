#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
//O(nm), some notes, ideas to see what happened in nth iteration
// find negative cycle if decrease in nth iterarion
// for maximum algorithm, if increase, positive cycles
const int N = 5005;
 
struct Edge{
    ll u, v, w;
};
vector<Edge> edges;
ll dist[N];
 
bool infinite_cycle_bellman(int n){
    int cur, x;
    ll MIN_LL;
    memset(dist, 192, sizeof(dist));
    memset(&MIN_LL, 192, sizeof(MIN_LL));
    dist[1] = 0;
    bool inf = false;
    set<int> cyc;
    for(int i=0;i<=(2*n);i++){
        for(auto edge : edges){
            if(dist[edge.u] == MIN_LL) continue;
            if(dist[edge.v] < dist[edge.u] + edge.w){
                dist[edge.v] = dist[edge.u] + edge.w;
                if(i >= n) cyc.insert(edge.v);
            }   
        }
    }
    bool ok1=false, okn=false;
    for(auto edge : edges){
        if(edge.u == 1 && cyc.count(edge.v)) ok1 = true;
        if(edge.v == n && cyc.count(edge.u)) okn = true;
    }
    if(ok1 && okn) inf= true;
    return inf;
}
 
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
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
        ll a,b,w;
        cin >>a >> b >> w;
        edges.push_back({a,b,w});
    }
    if(infinite_cycle_bellman(n)){
        cout << -1;
    }else cout << dist[n];
}