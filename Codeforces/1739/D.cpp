#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cur, ans;
const int N = 2e5+3, M = 20;
int p[N], ord[N], invord[N], sub[N], h[N];

int anc[N][M], n, cnt = 0;

void dfs(vector<vector<int>> &adj, int u){
    ord[u] = ++cnt;
    invord[ord[u]] = u;
    anc[u][0] = p[u];
    sub[u] = 1;
    h[u] = h[p[u]] + 1;
    for(auto v : adj[u]){
        dfs(adj, v);
        sub[u] += sub[v];
    }
}

void build(int n){
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

int jmp(int a, int k){ 
    for(int i = M-1; i>=0;i--) if(k & (1 << i)) a = anc[a][i];
    return a;
}

void calc(vector<vector<int>> &adj){
    set<pair<int,int>> s;
    set<int> s2;
    for(int i=1;i<=n;i++) if(h[i] > cur){
         s.insert({h[i], ord[i]});
         s2.insert(ord[i]);
    }
    while(s.size()){
        ans++;
        auto [hv, vx] = *prev(s.end());
        vx = invord[vx];
        vx = jmp(vx, cur - 1);
        auto it = s2.lower_bound(ord[vx]);
        vector<int> erl;
        while(it != s2.end() && *it <= (ord[vx] + sub[vx] - 1)){
            erl.push_back(*it);
            s.erase({h[invord[*it]], *it});
            ++it;
        }
        for(auto x : erl) s2.erase(x);
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
        int k;
        cin >> n >> k;
        cnt = 0;
        vector<vector<int>> adj(n+1);
        for(int i=2;i<=n;i++){
            int par;
            cin >> par;
            adj[par].push_back(i);
            p[i] = par;
        }
        int lo = 1, hi = n-1;
        dfs(adj, 1);
        build(n);
        while(lo != hi){
            cur = lo + (hi - lo)/2;
            ans = 0;
            calc(adj);
            if(ans <= k) hi = cur;
            else lo = cur + 1;
        }
        cout << lo << "\n";
    }
}
