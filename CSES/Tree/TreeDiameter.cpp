#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+3;
int d[N];
vector<int> adj[N];

void bfs(int src){
    memset(d, 63, sizeof(d)); //this line must be done in main and skipped if multiples bfs
    queue<int> q;
    q.push(src); 
    d[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, farthest = 1, fard = 0;
    cin >> n;
    for(int i=2;i<=n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for(int i=2;i<=n;i++){
        if(d[i] > fard){
            fard = d[i];
            farthest = i;
        }
    }
    bfs(farthest);
    fard = 0;
    for(int i=1;i<=n;i++){
        fard = max(fard, d[i]);
    }
    cout << fard;
}
