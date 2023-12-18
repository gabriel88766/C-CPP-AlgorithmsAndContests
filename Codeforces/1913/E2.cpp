#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -INF_INT;
    else
        return cost;
}

int costv[100][100];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    int f1 = 0, f2 = 0;
    vector<int> a(n+1), b(m+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> costv[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
        f1 += a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
        f2 += b[i];
    }
    if(f1 != f2){
        cout << "-1\n";
    }else{      
        vector<Edge> v; 
        for(int i=1;i<=n;i++) v.push_back({0, i, a[i], 0});
        for(int i=1;i<=m;i++) v.push_back({n+i, n+m+1, b[i], 0});
        int curcst = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int w = costv[i][j] ? -1 : 1;
                curcst += costv[i][j];
                v.push_back({i, n+j, 1, w});
            }
        }
        int ansc = min_cost_flow(n+m+2, v, f1, 0, n+m+1);
        if(ansc != -INF_INT){
            cout << ansc + curcst << "\n";
        }else cout << "-1\n";
    }
}
