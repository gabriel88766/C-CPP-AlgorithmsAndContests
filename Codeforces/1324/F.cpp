#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int n, rt;
vector<int> adj[N];
int col[N];
int ans[N];
int cnt[N];

void dfs1(int u,int p){
    if(col[u]) cnt[u] = 1;
    else cnt[u] = -1;
    for(auto v: adj[u]){
        if(v != p){
            dfs1(v, u);
            if(cnt[v] > 0) cnt[u] += cnt[v]; 
        }
    }
    //if(cnt[u] >= 0) used[u] = true;
}

void dfs2(int u, int p, int ansp){
   // cout << u << " " << ansp << " " << cnt[u] << "\n";
    ansp = max(ansp, 0);
    ans[u] = ansp + cnt[u];
    int tt = col[u] ? 1 : -1;
    for(auto v : adj[u]){
        if(v != p){
            if(cnt[v] >= 0) tt += cnt[v];
        }
    }
    for(auto v : adj[u]){
        if(v != p){
            if(cnt[v] >= 0) dfs2(v, u, tt+ansp-cnt[v]);
            else dfs2(v, u, tt+ansp);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> col[i];
        if(col[i] == 1){
            rt = i;
        }
    }
    
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(!rt){
        for(int i=1;i<=n;i++) cout << "-1 ";
        return 0;
    }
    //cout << rt << "\n";
    dfs1(rt, 0);
    dfs2(rt, 0, 0);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}   
