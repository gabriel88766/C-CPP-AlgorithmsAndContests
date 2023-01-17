#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acosl(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7, MOD2 = 2e9+11;
const int N = 2e5+5;
//vector<vector<int>> matrix(row,vector<int>(col));
// cout << setprecision(10) << fixed << variableLD;
int n,m,bp,ep;
vector<int> adj[N];
int  sub[N];
char visited[N];

long long int ans[N],dist[N];

void dfs(int u, int p=0){
    for(auto v : adj[u]){
        if(v!=p) dfs(v,u);
    }
    sub[p] += (sub[u]+1);
    ans[p] += (sub[u]+ans[u]+1);

}
void bfs( int rt){



    queue<int> q;
    q.push(rt);
    visited[1] = true;

    while (!q.empty()) {
      int u = q.front(); q.pop();
      visited[u] = true;
        for (int v : adj[u]) if (!visited[v])
          dist[v] = dist[u] + n - 2 - 2*sub[v], q.push(v);
    }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i=2;i<=n;i++){
      int a,b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  dfs(1);
  dist[1] = ans[1];
  bfs(1);
  for(int i=1;i<=n;i++){
    cout << dist[i] << " ";
  }

}
