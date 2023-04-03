#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
int d1[N], d2[N], n;

void bfs1(int src){
    memset(d1, 63, sizeof(d1));
    queue<int> q;
    q.push(src); 
    d1[src] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : adj[u]){
            if(d1[u] + 1 < d1[v]){
                d1[v] = d1[u] + 1; q.push(v);
            }
        }
    }
}
void bfs2(int src){
    memset(d2, 63, sizeof(d2));
    queue<int> q;
    q.push(src); 
    d2[src] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : adj[u]){
            if(d2[u] + 1 < d2[v]){
                d2[v] = d2[u] + 1; q.push(v);
            }
        }
    }
}

vector<int> farth1, farth2;
int diameter(){ //node first to second is the diameter.
    bfs1(1);
    int fart = 1, maxd = 0;
    for(int i=2;i<=n;i++) if(d1[i] > maxd) maxd = d1[i], fart = i;
    bfs1(fart);
    maxd = 0;
    for(int i=1;i<=n;i++) if(d1[i] > maxd) maxd = d1[i];
    for(int i=1;i<=n;i++) if(d1[i] == maxd) farth1.push_back(i);
    bfs2(farth1.back());
    for(int i=1;i<=n;i++) if(d2[i] == maxd) farth2.push_back(i);
    return maxd;
}

vector<int> dist[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int x = diameter();
    for(int i=1;i<=n;i++){
        dist[max(d1[i], d2[i])].push_back(i);
    }
    int cur = n;
    vector<int> ans(n+1);
    for(int i=x+1;i<=n;i++) ans[i] = n;
    ans[x] = n - dist[x].size()+1;
    for(int i=x-1;i>=1;i--){
        ans[i] = ans[i+1] - dist[i].size();
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}
