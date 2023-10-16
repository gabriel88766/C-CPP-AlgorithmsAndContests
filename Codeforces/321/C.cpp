#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
char ans[N];
struct centroid{
    vector<bool> ac;
    vector<int> sub;
    vector<int> par; //parent array after dec.
    vector<vector<int>> tree; //old tree
    vector<vector<int>> adj;
    vector<vector<int>> anc;
    vector<int> h;
    int rt; //after dec
    void dfsT(int u, int p){
        sub[u] = 1;
        for(auto v : tree[u]){
            if(v != p && !ac[v]){
                dfsT(v, u);
                sub[u] += sub[v];
            }
        }
    }
    int find_centroid(int u){
        dfsT(u, 0);
        int sz = sub[u]/2, p = 0;
        while(true){
            int nxt = 0;
            for(auto v: tree[u]){
                if(!ac[v] && sub[v] > sz && v != p){
                    nxt = v;
                }
            }
            if(nxt){
                p = u;
                u = nxt;
            }else break;
        }
        return u;
    }
    void build_distances(){
        anc.resize(tree.size());
        h.resize(tree.size());
        h[0] = -1;
        for(int i=0;i<tree.size();i++) anc[i].resize(20);
        function<void(int,int)> dfs = [&](int u, int p){
            anc[u][0] = p;
            h[u] = h[p] + 1;
            for(auto v : tree[u]){
                if(v != p){
                    dfs(v, u);
                }
            }
        };
        dfs(1, 0);
        for(int i=1;i<20;i++){
            for(int j=1;j<tree.size();j++){
                anc[j][i] = anc[anc[j][i-1]][i-1];
            }
        }
    }
    int dist(int a, int b){ //O(log n);
        int ans = 0;
        if(h[a] > h[b]) swap(a, b);
        for(int i=19;i>=0;i--){
            if(h[a] + (1 << i) <= h[b]){
                ans += (1 << i);
                b = anc[b][i];
            }
        }
        if(a == b) return ans;
        for(int i=19;i>=0;i--){
            if(anc[a][i] != anc[b][i]){
                ans += 2 * (1 << i);
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        return ans + 2;
    }
    void build(){
        sub.resize(tree.size());
        par.resize(tree.size());
        adj.resize(tree.size());
        ac.assign(tree.size(), false);
        rt = find_centroid(1);
        ac[rt] = true;
        queue<int> q;
        q.push(rt);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v : tree[u]){
                if(!ac[v]){
                    int t = find_centroid(v);
                    adj[u].push_back(t);
                    par[t] = u;
                    ac[t] = true;
                    q.push(t);
                }
            }
        }
        //build_distances();
    }
    void solve(int n){
        queue<int> q;
        q.push(rt);
        memset(ans, 'Z'+1, sizeof(ans));
        ans[rt] = 'A';
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v : adj[u]){
                ans[v] = ans[u] + 1;
                q.push(v);
            }
        }
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    centroid c;
    c.tree.resize(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        c.tree[a].push_back(b);
        c.tree[b].push_back(a);
    }
    c.build();
    c.solve(n);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}
