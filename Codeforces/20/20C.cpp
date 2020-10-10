#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

typedef long long ll;

typedef pair<long long int, long long int> pll;
typedef vector<long long int> vl;

const int N = 1e5+5;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

vl adj[N], adjw[N];
ll dist[N];
int p[N];

void dijkstra(){
    cl(dist,63);
    dist[1]=0;
    priority_queue<pll> pq;
    pq.push(mp(0,1));

    while (!pq.empty()) {
      int u = pq.top().nd;
      int d = -pq.top().st;
      pq.pop();


      if (d > dist[u]) continue;
      for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        int w = adjw[u][i];
        if (dist[u] + w < dist[v]){
          dist[v] = dist[u]+w;
          p[v]=u;
          pq.push(mp(-dist[v], v));
      }
    }
    }
}

vector<int> recoverPath(int n){
    int i=n;
    vector<int> ans;
    while(i!=1){
        ans.push_back(i);
        i=p[i];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n,m,a,b,w;
    vector<int> path;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adjw[a].push_back(w);
        adj[b].push_back(a);
        adjw[b].push_back(w);
    }
    dijkstra();

    if(dist[n]!=INF){
        path=recoverPath(n);
        for( int i=0;i<path.size();i++){
            cout << path[i] << " ";
        }
    }else{
        cout << -1;
    }

}


