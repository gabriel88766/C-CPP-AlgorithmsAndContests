#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
vector<int> adj[N], adjb[N], adjw[N];
int dist[N];
int n;
int t0, ta, tb;

bool dijkstra(int ts){
    for(int i=2;i<=n;i++) dist[i] = INF_INT;
    dist[1] = ts;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ts, 1});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            int wb;
            if(d + adjb[u][i] <= ta) wb = d + adjb[u][i];
            else wb = max(d, tb) + adjb[u][i];
            int ww = d + adjw[u][i];
            int w = min(ww, wb);
            if(dist[v] > w){
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[n] <= t0;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        cin >> t0 >> ta >> tb;
        for(int i=0;i<m;i++){
            int a, b, t1, t2;
            cin >> a >> b >> t1 >> t2;
            adj[a].push_back(b);
            adjb[a].push_back(t1);
            adjw[a].push_back(t2);
            adj[b].push_back(a);
            adjb[b].push_back(t1);
            adjw[b].push_back(t2);
        }
        if(dijkstra(0)){
            int lo = 0, hi = t0;
            while(lo != hi){
                int mid = lo + (hi - lo + 1)/2;
                if(dijkstra(mid)) lo = mid;
                else hi = mid - 1;
            }
            cout << lo << "\n";
        }else cout << "-1\n";




        //clear
        for(int i=1;i<=n;i++){
            adj[i].clear();
            adjb[i].clear();
            adjw[i].clear();
        }
    }
}
