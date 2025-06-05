#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int sub[N], ord[N], par[N], cnt = 0;
pair<int, int> vtx[N];
vector<int> adj[N];
ll ans[N], rans[N];
void dfs(int u, int p){
    par[u] = p;
    ord[u] = ++cnt;
    sub[u] = 1;
    for(auto &v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        vtx[i] = {a, b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int tq, e, x;
        cin >> tq >> e >> x;
        int v, p;
        if(tq == 1) v = vtx[e].first, p = vtx[e].second;
        else v = vtx[e].second, p = vtx[e].first;
        if(par[v] == p){
            //then update in sub[v]
            ans[ord[v]] += x;
            ans[ord[v] + sub[v]] -= x;
        }else{
            //then update everywhere, except sub[p]
            ans[1] += x;
            ans[n+1] -= x; //useless
            ans[ord[p]] -= x;
            ans[ord[p]+sub[p]] += x;
        }
    }
    for(int i=1;i<=n;i++){
        ans[i] += ans[i-1];
        // if ord[u] == i, then rans[u] = ans[i]
    }
    for(int u=1;u<=n;u++){
        rans[u] = ans[ord[u]];
    }
    for(int i=1;i<=n;i++){
        cout << rans[i] << "\n";
    }
}
