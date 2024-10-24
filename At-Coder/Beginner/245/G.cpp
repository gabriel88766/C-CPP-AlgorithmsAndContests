#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;

int a[N];
vector<ll> adj[N], adjw[N];
pair<ll,ll> dist[N][2];

void dijkstra(vector<int> src){
    memset(dist, 63, sizeof(dist));
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
    for(auto x : src){
        dist[x][0] = {0, a[x]};
        pq.push({0, x, 0});
    }
    
    
    while(!pq.empty()){
        auto [d, u, j] = pq.top();
        pq.pop();
        if(d != dist[u][j].first) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], w = adjw[u][i];
            if(dist[v][0].second == dist[u][j].second){
                if(w + d < dist[v][0].first){
                    dist[v][0].first = w + d;
                    pq.push({dist[v][0].first, v, 0});
                }   
            }else if(dist[v][1].second == dist[u][j].second){
                if(w + d < dist[v][1].first){
                    dist[v][1].first = w + d;
                    if(dist[v][1].first < dist[v][0].first){
                        swap(dist[v][1], dist[v][0]);
                        pq.push({dist[v][1].first, v, 1});
                        pq.push({dist[v][0].first, v, 0});
                    }else{
                        pq.push({dist[v][1].first, v, 1});
                    }
                }
            }else{
                if(w + d < dist[v][0].first){
                    swap(dist[v][0], dist[v][1]);
                    dist[v][0].first = w + d;
                    dist[v][0].second = dist[u][j].second;
                    pq.push({dist[v][0].first, v, 0});
                    pq.push({dist[v][1].first, v, 1});
                }else if(w + d < dist[v][1].first){
                    dist[v][1].first = w + d;
                    dist[v][1].second = dist[u][j].second;
                    pq.push({dist[v][1].first, v, 1});
                }
            }
            
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> src;
    for(int i=1;i<=l;i++){
        int x;
        cin >> x;
        src.push_back(x);
    }
    for(int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adjw[a].push_back(w);
        adj[b].push_back(a);
        adjw[b].push_back(w);
    }
    dijkstra(src);
    for(int i=1;i<=n;i++){
        if(dist[i][0].first < INF_LL && dist[i][0].second != a[i]) cout << dist[i][0].first << " ";
        else if(dist[i][1].first < INF_LL && dist[i][1].second != a[i]) cout << dist[i][1].first << " ";
        else cout << "-1 ";
    }
    cout << "\n";
}
