#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
vector<int> adj[N];
int dp[N][21];
int val[N];

void dfs(int u, int p){
    priority_queue<pair<int,pair<int, int>>> pq;
    pq.push({val[u], {u, -1}});
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            pq.push({dp[v][1], {v, 1}});
        }
    }
    int cnt = 0;
    while(!pq.empty() && cnt < 20){
        auto [val, p2] = pq.top();
        pq.pop();
        auto [v1, pp] = p2;
        dp[u][++cnt] = val;
        if(v1 != u && pp < 20 && dp[v1][pp+1] > 0){
            pq.push({dp[v1][pp+1], {v1, pp+1}});
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> val[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=0;i<q;i++){
        int v, k;
        cin >> v >> k;
        cout << dp[v][k] << "\n";
    }
}   
