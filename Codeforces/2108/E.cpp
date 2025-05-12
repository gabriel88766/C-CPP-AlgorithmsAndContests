#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int sub[N], par[N], h[N];
int n;
void dfs1(int u, int p){
    sub[u] = 1;
    for(auto &v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
}
int find_centroid(int u, int p){
    for(auto &v : adj[u]){
        if(v != p){
            if(sub[v] > n/2) return find_centroid(v, u);
        }
    }
    return u;
}

pair<int, int> rm;
int sub2[N];
void dfs2(int u, int p){
    sub2[u] = 0;
    h[u] = h[p] + 1;
    par[u] = p;
    for(auto &v : adj[u]){
        if(v != p){
            dfs2(v, u);
            sub2[u] += sub2[v];
        }
    }
    int cur = sub2[u] + h[u]; 
    sub2[u] += 1;
    if(cur < rm.first){
        rm = {cur, u};
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    h[0] = -1;
    while(t--){
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs1(1, 0);
        int ct = find_centroid(1, 0);
        rm = {INF_INT, INF_INT};
        dfs2(ct, 0);
        int u = rm.second;
        int v = par[u];
        if(u > v) swap(u, v);
        cout << u << " " << v << "\n";
        vector<int> ans(n+1, 0); //ans[v] = 0. IF v is centroid, then do nothing, else, append centroid when visiting
        vector<vector<int>> vv;
        vector<int> cur;
        function<void(int, int)> dfs3 = [&](int c, int p){
            if(c == v) cur.push_back(ct);
            else cur.push_back(c);
            for(auto &x : adj[c]){
                if(x != p){
                    dfs3(x, c);
                }
            }
        };
        priority_queue<pair<int, int>> pq;
        for(auto &x : adj[ct]){
            cur.clear();
            dfs3(x, ct);
            vv.push_back(cur);
            pq.push({cur.size(), vv.size() - 1});
        }
        int color = 0;
        while(pq.size()){
            assert(pq.size() >= 2);
            auto [a, b] = pq.top();
            pq.pop();
            auto [c, d] = pq.top();
            pq.pop();
            ans[vv[b].back()] = ans[vv[d].back()] = ++color;
            vv[b].pop_back();
            vv[d].pop_back();
            if(vv[b].size()) pq.push({vv[b].size(), b});
            if(vv[d].size()) pq.push({vv[d].size(), d});
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }

}
