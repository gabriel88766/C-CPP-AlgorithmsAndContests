#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
ll dist[N][2];
vector<int> adj[N], ivj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, x;
    cin >> n >> m >> x;
    memset(dist, 63, sizeof(dist));
    dist[1][0] = 0, dist[1][1] = x;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    pq.push({0, 1, 0});
    pq.push({x, 1, 1});
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ivj[b].push_back(a);
    }
    while(!pq.empty()){
        auto [a, b, c] = pq.top();
        pq.pop();
        if(dist[b][c] < a) continue;
        if(dist[b][c^1] > dist[b][c] + x){
            dist[b][c^1] = dist[b][c] + x;
            pq.push({dist[b][c^1], b, c^1});
        }
        auto &cur = c == 1 ? ivj[b] : adj[b];
        for(auto &v : cur){
            if(dist[v][c] > dist[b][c] + 1){
                dist[v][c] = dist[b][c] + 1;
                pq.push({dist[v][c], v, c});
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]) << "\n";
}
