#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int tin[N], lowb[N], par[N];

int tnode = 0;
set<pair<int, int>> bdg;
//made from scratch again... (to learn again)
//based on dfstree, a bridge is an edge such that its DFStree from child hasn't backedge to any parent
void find_bridges(int u, int p = 0){
    //to find path
    par[u] = p;
    //now bridges.
    lowb[u] = tin[u] = ++tnode;
    for(auto v : adj[u]){
        if(v == p) continue; //parent, isnt back edge nor child
        if(!tin[v]){
            //child
            find_bridges(v, u);
        }else{
            //back edge
            //do nothing, same assign as child
        }
        lowb[u] = min(lowb[u], lowb[v]);
        if(tin[u] < lowb[v]){
            //then it is a bridge
            bdg.insert({min(u, v), max(u, v)});
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        map<pair<int, int>, int> mp;
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            mp[{min(a,b), max(a,b)}] = i;
        }
        find_bridges(1);
        int x = n;
        vector<pair<int, int>> dist(n+1, make_pair(INF_INT, INF_INT));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        while(x != 1){
            int nv = par[x];
            int mn = min(x, nv), mx = max(x, nv);
            if(bdg.count({mn, mx})){
                dist[x] = min(dist[x], {0, mp[{mn, mx}]});
                dist[nv] = min(dist[nv], {0, mp[{mn, mx}]});
            }
            x = nv;
        }
        for(int i=1;i<=n;i++){
            if(dist[i].first == 0) pq.push({dist[i].first, dist[i].second, i});
        }
        while(pq.size()){
            auto [dx, j, u] = pq.top();
            pq.pop();
            if(dist[u] != make_pair(dx, j)) continue;
            for(auto v : adj[u]){
                if(dist[v] > make_pair(dist[u].first + 1, dist[u].second)){
                    dist[v] = {dist[u].first + 1, dist[u].second};
                    pq.push({dist[v].first, dist[v].second, v});
                }
            }
        }
        int qr;
        cin >> qr;
        for(int i=1;i<=qr;i++){
            int xc;
            cin >> xc;
            if(dist[xc].first != INF_INT) cout << dist[xc].second << " ";
            else cout << "-1 ";
        }
        cout << "\n";
        //clear
        for(int i=1;i<=n;i++){
            adj[i].clear();
            par[i] = tin[i] = lowb[i] = 0;
        }
        bdg.clear();
        tnode = 0;
    }
}
