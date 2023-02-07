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
        x=-1; //if x changed in last iteration, thus x is part of a negative cycle.
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
    if(negative_cycle_bellman(n)){
        cout << "YES\n";
        for(auto u : cycle) cout << u << " ";
    }else cout << "NO";
}
