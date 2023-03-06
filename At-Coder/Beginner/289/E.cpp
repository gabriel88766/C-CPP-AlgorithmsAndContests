#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
int c[N];
int dist[N*N];
vector<int> adj[N];


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i =1;i<=n;i++) cin >> c[i];
        for(int i=1; i<=m;i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<(n*n);i++) dist[i] = INF_INT;
        //src  = (1, n) = n-1, dest = (n, 1) = (n-1)*n
        queue<int> q;
        q.push(n-1);
        dist[n-1] = 0;
        while(!q.empty()){
            int state = q.front();
            int st = state / n + 1;
            int nd = state % n + 1;
            q.pop();
            for(auto x : adj[st]){
                for(auto y : adj[nd]){
                    if(c[x] != c[y]){
                        int newstate = (x-1)*n + y-1;
                        if(dist[newstate] > dist[state] + 1){
                            dist[newstate] = dist[state] + 1;
                            q.push(newstate);
                        }
                    }
                }
            }
        }
        if(dist[(n-1)*n] != INF_INT) cout << dist[(n-1)*n] << "\n";
        else cout << "-1\n";

        //for nxt
        for(int i =1;i<=n;i++) {c[i] = 0; adj[i].clear();}
    }
}
