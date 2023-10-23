#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
vector<pair<ll,ll>> dist[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        adj[a].push_back(b);
        dist[a].push_back({x, y});
        adj[b].push_back(a);
        dist[b].push_back({-x,-y});
    }
    vector<pair<ll,ll>> place(n+1);
    vector<bool> vis(n+1, false);
    vis[1] = true;
    place[1] = {0, 0};
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(!vis[adj[u][i]]){
                place[adj[u][i]] = {place[u].first + dist[u][i].first, place[u].second + dist[u][i].second};
                vis[adj[u][i]] = true;
                q.push(adj[u][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) cout << "undecidable\n";
        else cout << place[i].first << " " << place[i].second << "\n";
    }
}
