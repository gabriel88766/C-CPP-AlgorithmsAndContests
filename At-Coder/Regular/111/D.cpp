#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 105;
int dir[N*N], c[N];
bool vis[N];
vector<int> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edg;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        edg.push_back({a, b});
    }
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=0;i<m;i++){
        auto [a, b] = edg[i];
        if(c[a] != c[b]){
            if(c[a] > c[b]) dir[i] = 1;
            else dir[i] = 2;
        }else{
            adj[a].push_back(i);
            adj[b].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            function<void(int)> dfs = [&](int u){
                vis[u] = true;
                for(auto &j : adj[u]){
                    auto [a, b] = edg[j];
                    if(u == a) dir[j] = 1;
                    else dir[j] = 2;
                    int an = a == u ? b : a;
                    if(!vis[an]) dfs(an);
                }
            };
            dfs(i);
        }
    }
    for(int i=0;i<m;i++){
        if(dir[i] == 1) cout << "->\n";
        else cout << "<-\n";
    }
}
