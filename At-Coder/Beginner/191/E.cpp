#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
vector<pair<int, int>> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for(int i=1;i<=n;i++){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        vector<int> dist(n+1, INF_INT);
        while(pq.size()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [v, w] : adj[u]){
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        if(dist[i] == INF_INT) cout << "-1\n";
        else cout << dist[i] << "\n";
    }
}
