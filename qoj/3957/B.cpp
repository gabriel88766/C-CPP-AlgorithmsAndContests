#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n, k;
const int N = 1e5+3;
vector<int> adj[N], ans;
int d[N];
void dfs(int u, int p){
    int mx = 1;
    for(auto v : adj[u]){
        dfs(v, u);
        mx = max(mx, d[v] + 1);
    }
    d[u] = mx;
    if(d[u] == k || u == 1){
        d[u] = 0;
        ans.push_back(u);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> k;
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs(1, 0);
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
