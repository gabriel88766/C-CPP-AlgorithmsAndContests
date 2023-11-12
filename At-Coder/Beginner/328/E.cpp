#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(vector<vector<int>> &adj){
    int src = 1;
    int n = adj.size() - 1;
    vector<bool> vis(adj.size(), false);
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for(int i=1;i<adj.size();i++) if(!vis[i]) return false;
    return true;
}

struct Edge{
    int u, v;
    ll w;
};

ll k;
int tte;
int n, m;
int ch[10];
vector<Edge> v;

ll solve(int sz, int cur){
    if(sz == tte){
        ll ttw = 0;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<sz;i++){
            int u = v[ch[i]].u;
            int d = v[ch[i]].v;
            ll w = v[ch[i]].w;
            ttw += w;
            adj[u].push_back(d);
            adj[d].push_back(u);
        }
        if(check(adj)) return ttw % k;
        else return INF_LL;
    }
    ll ans = INF_LL;
    for(int i=cur+1;i<=m;i++){
        ch[sz++] = i; 
        ans = min(ans, solve(sz, i));
        sz--;
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m >> k;
    tte = n-1;
    v.resize(m+1);
    for(int i=1;i<=m;i++){
        int u, d;
        ll w;
        cin >> u >> d >> w;
        v[i].u = u;
        v[i].v = d;
        v[i].w = w;
    }
    cout << solve(0, 0);
}
