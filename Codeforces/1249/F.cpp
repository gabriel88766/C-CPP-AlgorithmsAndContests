#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 205;
vector<int> adj[N];
int dp[N][N];
int mx[N][N];
int a[N];
int n, k;
void dfs(int u, int p){
    dp[u][0] = a[u];
    int sum = 0;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            dp[u][0] += mx[v][k];
            dp[u][k] += mx[v][k-1];
        }
    }
    for(int j=1;j<=k;j++){
        //j, max(k-j-1, j)
        int rj = j - 1;
        int ot = max(k - rj - 1, rj);
        for(auto v : adj[u]){
            if(v != p){
                int cur = dp[v][rj];
                for(auto x : adj[u]){
                    if(x != p && x != v){
                        cur += mx[x][ot];
                    }
                }
                dp[u][j] = max(dp[u][j], cur);
            }
        }
    }
    for(int j=k;j>=0;j--){
        mx[u][j] = dp[u][j];
        mx[u][j] = max(mx[u][j], mx[u][j+1]);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << mx[1][0] << "\n";
}
