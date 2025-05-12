#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct centroid{
    vector<bool> ac;
    vector<int> sub;
    vector<int> par; //parent array after dec.
    vector<vector<int>> tree; //old tree
    vector<vector<int>> adj;
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
    }
};


int ask(vector<int> &v){
    cout << "? ";
    for(auto &x : v) cout << x << " ";
    cout << "\n";
    cout.flush();
    int ans = 0;
    if(v[0] == 1) cin >> ans;
    return ans;
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
        cin >> n;
        vector<vector<int>> adj(n+1);
        vector<int> ansv(n+1, 0);
        centroid ct;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ct.tree = adj;
        ct.build();
        auto checkrt = [&](int u){ //3 queries
            int sz = adj[u].size();
            vector<int> qr = {1, sz};
            for(auto &x : adj[u]) qr.push_back(x);
            int ans = ask(qr);
            vector<int> q2 = {2, u};
            ask(q2);
            int ans2 = ask(qr);
            if(abs(ans - ans2) == 2*adj[u].size()) return true;
            else return false;
        };

        //FIND THE ROOT
        function<int(int)> findrt = [&](int u){
            if(checkrt(u)) return u;
            else{
                int l = 0, r = ct.adj[u].size() - 1;
                while(l != r){
                    int m = (l + r) / 2;
                    vector<int> cq = {1, m-l+1};
                    vector<int> ax = {2, u};
                    for(int i=l;i<=m;i++) cq.push_back(ct.adj[u][i]);
                    int a1 = ask(cq);
                    ask(ax);
                    int a2 = ask(cq);
                    if(abs(a1-a2) == 2*(m - l + 1)) l = m+1;
                    else r = m;
                }
                return findrt(ct.adj[u][l]);
            }
        };

        //END FIND THE ROOT
        int cs = 0;
        function<void(int u, int p)> solve = [&](int u, int p){
            vector<int> cv = {1, 1, u};
            ansv[u] = ask(cv) - cs;
            cs += ansv[u];
            for(auto &v : adj[u]){
                if(v != p) solve(v, u);
            }
            cs -= ansv[u];
        };
        int rt = findrt(ct.rt); //need to find root in less than 200 queries;
        solve(rt, 0);
        cout << "! ";
        for(int i=1;i<=n;i++) cout << ansv[i] << " ";
        cout << "\n";
        cout.flush();
    }
}
