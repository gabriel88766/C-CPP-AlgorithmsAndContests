#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 205, M = 2e5+3;
int p[M]; // 0 if prime, 1 if not prime
void sieve(){
    for(ll i=2; i<M; i++){
        if(!p[i]){
            for(ll j = i*i; j < M; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
        }
    }
}
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N];

// for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
void tarjan(int u){ //SCC, cmp is in inverse topological order 
    dfs_low[u] = dfs_num[u] = ++cntT;
    visc[u] = 1;
    curcmp.emplace_back(u);
    for(auto v : adj[u]){
        if(!dfs_num[v]) tarjan(v);
        if(visc[v] == 1) dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++cntCmp;
        while(true){
            int v = curcmp.back(); curcmp.pop_back(); visc[v] = 2;
            cmp[cntCmp].emplace_back(v);
            if(v == u) break;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int n, k;
    cin >> n >> k;
    vector<tuple<int,int,int>> vt(n);
    for(int i=0;i<n;i++){
        int p, c, l;
        cin >> p >> c >> l;
        vt[i] = {p, c, l};
    }
    sort(vt.begin(), vt.end(), [&](tuple<int,int,int> u, tuple<int,int,int> v){
        auto [p1, c1, l1] = u;
        auto [p2, c2, l2] = v;
        return l1 < l2;
    });
    bool ok = false;
    for(int i=1;i<=n;i++){
        int mind = -1;
        for(auto [p, c, l] : vt){
            if(l <= i) mind++;
            else break;
        }
        if(mind == -1) continue;
        //build 2 sat
        for(int u=0;u<mind;u++){
            for(int v = u+1; v < mind; v++){
                auto [p1, c1, l1] = vt[u];
                auto [p2, c2, l2] = vt[v];
                if(!p[c1 + c2]){
                    // l1 -> !l2 && l2 -> !l1 from 0 to 2n-1, pos = 2i, neg = 2i+1
                    adj[2*l1].push_back(2*l2+1);
                    adj[2*l2].push_back(2*l1+1);
                }
            }
        }
        for(int j=0;j<2*n;j++) if(visc[j] == 0) tarjan(j);
        

        for(int j=0;j<2*n;j++){
            adj[j].clear();
            visc[j] = false;
            cmp[j].clear();
            dfs_low[j] = dfs_num[j] = 0;
        }
        cntCmp = cntT = 0;
        curcmp.clear();
    }
    if(!ok) cout << "-1\n";
}
