#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
struct edge {ll v, c, f;};
vector<edge> edgs;
vector<int> g[N];
void add_edge (ll u, ll v, ll c) {
    int k = edgs.size();
    edgs.push_back({v, c, 0});
    edgs.push_back({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k+1);
}
int src, snk;

ll bfs(vector<int> &par){
    fill(par.begin(), par.end(), -1);
    queue<pair<ll, ll>> q;
    q.push({src, INF_LL});
    par[src] = -2;
    while(!q.empty()){
        auto [u, flow] = q.front();
        q.pop();
        for(auto v : g[u]){
            if(edgs[v].c > edgs[v].f && par[edgs[v].v] == -1){
                par[edgs[v].v] = v^1;
                ll nxt = min(flow, edgs[v].c - edgs[v].f);
                q.push({edgs[v].v, nxt});
                if(edgs[v].v == snk) return nxt;
            }
        }
    }
    return 0;
}

ll maxflow(int n){
    ll flow = 0;
    ll next_flow;
    vector<int> par(n+1);
    while(next_flow = bfs(par)){
        flow += next_flow;
        int cur = snk;
        while(cur != src){
            int k = par[cur];
            edgs[k].f -= next_flow;
            edgs[k^1].f += next_flow;
            cur = edgs[k].v;
        }
    }
    return flow;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int nn;
    cin >> nn;
    vector<int> a(nn+1), b(nn+1);
    int f1 = 0, f2 = 0;
    for(int i=1;i<=nn;i++){
        cin >> a[i];
        f1 += a[i];
    }
    for(int i=1;i<=nn;i++){
        cin >> b[i];
        f2 += b[i];
    }
    if(f1 != f2){
        cout << "-1\n";
    }else{
        src = 0, snk = 2*nn+1;
        for(int i=1;i<=nn;i++) add_edge(0, i, a[i]);
        for(int i=1;i<=nn;i++) add_edge(nn+i, 2*nn+1, b[i]);
        for(int i=1;i<=nn;i++){
            for(int j=1;j<=nn;j++){
                add_edge(i, nn+j, 1);
            }
        }
        auto mf = maxflow(2*nn+1);
        if(mf == f1){
            vector<vector<char>> ans(nn+1,vector<char>(nn+1));
            for(int i=1;i<=nn;i++){
                for(auto k : g[i]){
                    auto edg = edgs[k];
                    if(edg.c > 0){
                        if(edg.c == edg.f) ans[i][edg.v-nn] = 'X';
                        else ans[i][edg.v-nn] = '.'; 
                    }
                }
            }
            for(int i=1;i<=nn;i++){
                for(int j=1;j<=nn;j++){
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        }else cout << "-1\n";
    }
}
