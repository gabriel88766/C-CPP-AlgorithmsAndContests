#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n, k;
int hf = 0;
const int N = 2005;
vector<int> adj[N];
int h[N], dp1[N], dp2[N];

void dfs(int u, int p){
    h[u] = h[p] + 1;
    if(h[u] <= hf) dp1[u] = 1;
    else dp1[u] = 0;
    if(h[u] == hf + 1) dp2[u] = 1;
    else dp2[u] = 0;
    for(auto &v : adj[u]){
        if(v != p){
            dfs(v, u);
            dp1[u] += dp1[v];
            dp2[u] += dp2[v];
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> k;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    h[0] = -1;
    hf = k / 2;
    int ans = 0;
    for(int i=1;i<=n;i++){
        dfs(i, 0);
        int mx = 0;
        int cs = 1;
        for(auto x : adj[i]){
            cs += dp1[x];
            if(k % 2) mx = max(mx, dp2[x]);
        }
        ans = max(ans, cs + mx);
    }
    cout << n-ans << "\n";
}
