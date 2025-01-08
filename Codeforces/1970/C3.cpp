#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int wl[N], wl2[N];
void dfs(int u, int p){
    for(auto v: adj[u]){
        if(v != p){
            dfs(v, u);
            if(wl[v] == 0) wl[u]++;
        }
    }
}

//ch is the longest chain 0 1 0 1 0 1 0 1 ...
void dfs2(int u, int p, int ch){
    for(auto v: adj[u]){
        if(v != p){
            if(min(wl[u], wl[v]) == 0 && max(wl[u], wl[v]) == 1) dfs2(v, u, ch+1);
            else dfs2(v, u, 0);
        }
    }
    if(wl[u]) wl2[u] = 1;
    else if(ch % 2) wl2[u] = 1;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(1, 0, 0);
    for(int i=1;i<=k;i++){
        int x;
        cin >> x;
        if(wl2[x]) cout << "Ron\n";
        else cout << "Hermione\n";
    }
}
