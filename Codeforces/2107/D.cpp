#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5;
vector<int> adj[N];
bool rem[N];
int d[N], par[N];
vector<tuple<int, int, int>> vans;

vector<int> av;
void dfs(int u, int p = 0){
    av.push_back(u);
    for(auto &v : adj[u]){
        if(rem[v]) continue;
        if(v != p) dfs(v, u);
    }
}
void clear(){
    for(auto &x : av) d[x] = INF_INT; 
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    d[u] = 0;
    while(q.size()){
        auto u = q.front();
        q.pop();
        for(auto &v : adj[u]){
            if(rem[v]) continue;
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}
vector<int> find_diameter(int rt){
    av.clear();
    dfs(rt);
    clear();
    bfs(rt);
    vector<int> af;
    int md = 0;
    for(auto &x : av) md = max(md, d[x]);
    for(auto &x : av) if(md == d[x]) af.push_back(x);
    clear();
    bfs(af[0]);
    md = 0;
    for(auto &x : av) md = max(md, d[x]);
    for(auto &x : av) if(md == d[x]) af.push_back(x);
    int mf = *max_element(af.begin(), af.end());
    clear();
    bfs(mf);
    int m2 = 0;
    for(auto &x : av) if(md == d[x]) m2 = max(m2, x);
    vector<int> ans = {m2};
    while(m2 != mf){
        m2 = par[m2];
        ans.push_back(m2);
    }
    return ans;
}

void solve(int u){
    vector<int> nv;
    nv.push_back(u);
    while(nv.size()){
        auto u = nv.back();
        nv.pop_back();
        auto diam = find_diameter(u);
        vans.push_back({diam.size(), max(diam[0], diam.back()), min(diam[0], diam.back())});
        for(int i=0;i<diam.size();i++){
            int l = (i == 0 ? 0 : diam[i-1]);
            int r = (i == diam.size() - 1 ? 0 : diam[i+1]);
            for(auto &v : adj[diam[i]]){
                if(v == l || v == r || rem[v]) continue;
                nv.push_back(v);
            }
            rem[diam[i]] = true;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    // freopen("out", "w", stdout); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(1);
        sort(vans.begin(), vans.end(), greater<tuple<int, int, int>>());
        vector<int> ans;
        for(auto &[d, u, v] : vans){
            ans.push_back(d);
            ans.push_back(u);
            ans.push_back(v);
        }
        for(auto &x : ans) cout << x << " ";
        cout << "\n";
        for(int i=1;i<=n;i++) adj[i].clear(), rem[i] = false;
        vans.clear();
    }
}
