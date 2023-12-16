#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
vector<int> adj[N];
vector<int> a, b;
int k;
ll dist[N];

void bfs(int src){
    memset(dist, 63, sizeof(dist));
    if(b[0] == a[1]) dist[src] = 1;
    else dist[src] = 0;
    deque<int> dq;
    dq.push_back(src);
    while(!dq.empty()){
        auto u = dq.front();
        dq.pop_front();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            int w = dist[u] < k && b[dist[u]] == a[v] ? 1 : 0;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if(w){
                    dq.push_back(v);
                }else{
                    dq.push_front(v);
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
    int n, m;
    cin >> n >> m >> k;
    a.resize(n+1);
    b.resize(k);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<k;i++) cin >> b[i];
    bfs(1);
    if(dist[n] == k) cout << "Yes\n";
    else cout << "No\n";
}
