#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//hahahaha!!!
const int N = 2e5+3, M = 20; 
vector<int> adj[N];
int rt = 1, anc[N][M];

void dfs(int u, int par){ 
    anc[u][0] = par;
    for(auto x : adj[u]){
        if(x != par){
            dfs(x, u);
        }
    } 
}

void build(int n){
    dfs(rt, 0);
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

int anc_k(int a, int k){ //k-th ancestor in hierarchy
    int ans = a;
    for(int i=0;i<20;i++){
        if(k & (1 << i)) ans = anc[ans][i];
    }
    return ans;
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, q;
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a); //doesnt matter;
    }
    build(n);
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        int ans = anc_k(a, b);
        if(ans) cout << ans << "\n";
        else cout << "-1\n";
    }
}
