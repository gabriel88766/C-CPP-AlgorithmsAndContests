#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
bool marked[N];
int d1[N], d2[N];

void bfs(int *d, int src){
    queue<int> q;
    q.push(src); 
    d[src] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : adj[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1; q.push(v);
            }
        }
    }
}

void diameter(int n){ //node first to second is the diameter.
    for(int i=1;i<=n;i++) d1[i] = INF_INT;
    bfs(d1, 1);
    int fart1 = -1, maxd = -1, fart2 = -1;
    for(int i=1;i<=n;i++) if(d1[i] > maxd && marked[i]) maxd = d1[i], fart1 = i;
    //all distances d1
    for(int i=1;i<=n;i++) d1[i] = INF_INT;
    bfs(d1, fart1);
    maxd = -1;
    for(int i=1;i<=n;i++) if(d1[i] > maxd && marked[i]) maxd = d1[i], fart2 = i;
    //all distances d2
    for(int i=1;i<=n;i++) d2[i] = INF_INT;
    bfs(d2, fart2);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i=0;i<k;i++){
            int x;
            cin >> x;
            marked[x] = true;
        }
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        diameter(n);
        int ans = INF_INT;
        for(int i=1;i<=n;i++){
            ans = min(ans, max(d1[i], d2[i]));
        }
        cout << ans << "\n";

        for(int i=1;i<=n;i++){
            marked[i] = false;
            adj[i].clear();
        }
    }
}
