#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> pc(n+1);
    for(int i=1;i<=n;i++) cin >> pc[i];
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d(n+1, INF_INT);
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while(q.size()){
        auto u = q.front();
        q.pop();
        ans[pc[u]] = d[u];
        for(auto v : adj[u]){
            if(d[v] > d[u] + 1){
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    for(int i=1;i<=k;i++) cout << ans[i] << " ";
    cout << "\n";
}       
