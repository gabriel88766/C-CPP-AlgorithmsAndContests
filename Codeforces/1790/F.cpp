#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
basic_string<int> adj[N];
int c[N], d[N];
int n;
int cur;

void dfs(int u, int dis){
    d[u] = dis;
    if(dis + 1 >= cur) return;
    for(auto v : adj[u]){
        if(d[v] > dis+1){
            dfs(v, dis+1);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cur = INF_INT;
        for(int i=1;i<=n;i++){
             cin >> c[i];
             adj[i].clear();
             d[i] = INF_INT;
        }
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(c[1], 0);
        for(int i=2;i<=n;i++){
            cur = min(cur, d[c[i]]);
            cout << cur << " ";
            dfs(c[i], 0);
        }
        cout << "\n";
    }
}