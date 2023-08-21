#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1025;
vector<int> adj[N];
vector<int> adjw[N];


ll dist[N];

void dijkstra(int src){
    memset(dist, 63, sizeof(dist));
    dist[src] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], w = adjw[u][i];
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
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
        string s;
        cin >> s;
        int ini = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1') ini |= (1 << i);
        }
        for(int i=0;i<m;i++){
            int d;
            string s1, s2;
            cin >> d >> s1 >> s2;
            for(int j=0; j< (1 << n); j++){
                int dest = j;
                for(int k=0;k<n;k++){
                    if((dest & (1 << k)) && (s1[k] == '1')){
                        dest ^= (1 << k);
                    }
                    if((s2[k] == '1') && (!(dest & (1 << k)))){
                        dest ^= (1 << k);
                    }
                }
                if(dest != j){
                    adj[j].push_back(dest);
                    adjw[j].push_back(d);
                }
            }
        }
        dijkstra(ini);
        if(dist[0] == INF_LL) cout << "-1\n";
        else cout << dist[0] << "\n";
        for(int i=0;i < (1 << n); i++) {adj[i].clear(); adjw[i].clear();}
    }
}
