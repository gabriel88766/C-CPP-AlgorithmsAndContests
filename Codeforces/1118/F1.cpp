#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<int> adj[N];
int b[N], r[N];
int ttr, ttb;
void dfs(int u = 1, int p = 0){
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            b[u] += b[v];
            r[u] += r[v];
        }
    }
}
int ans = 0;
void dfs2(int u = 1, int p = 0){
    if(p != 0){
        if(r[u] == ttr && b[u] == 0) ans++;
        if(b[u] == ttb && r[u] == 0) ans++;
    }
    for(auto v : adj[u]){
        if(v != p){
            dfs2(v, u);
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
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        if(aux == 1) b[i] = 1;
        if(aux == 2) r[i] = 1;
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    ttr = r[1];
    ttb = b[1];
    dfs2();
    cout << ans << "\n";
}       
