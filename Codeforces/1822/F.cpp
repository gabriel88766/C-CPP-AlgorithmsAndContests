#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];

ll d[N], fartp[N], d1[N];

void bfs(int src){
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
    for(int i=1;i<=n;i++) d[i] = INF_INT;
    bfs(1);
    int fart1 = 1, maxd = 0, fart2 = 1;
    for(int i=1;i<=n;i++) d1[i] = d[i];
    for(int i=2;i<=n;i++) if(d[i] > maxd) maxd = d[i], fart1 = i;
    for(int i=1;i<=n;i++) d[i] = INF_INT;
    bfs(fart1);
    for(int i=1;i<=n;i++) fartp[i] = d[i];
    maxd = 0;
    for(int i=1;i<=n;i++) if(d[i] > maxd) maxd = d[i], fart2 = i;
    for(int i=1;i<=n;i++) d[i] = INF_INT;
    bfs(fart2);
    for(int i=1;i<=n;i++) fartp[i] = max(fartp[i], d[i]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k, c;
        cin >> n >> k >> c;
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        diameter(n);
        ll maxc = 0;
        for(int i=1;i<=n;i++) maxc = max(maxc, fartp[i]*k-d1[i]*c);
        cout <<maxc << "\n";

        for(int i=1;i<=n;i++) {adj[i].clear();}
    }
}
