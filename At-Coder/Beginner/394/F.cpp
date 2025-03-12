#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int ans = -1;
int dp[N];
void dfs(int u, int p){
    vector<int> vx;
    for(auto &v : adj[u]){
        if(v != p){
            dfs(v, u);
            vx.push_back(dp[v]);
        }
    }
    sort(vx.begin(), vx.end(), greater<int>());
    if(vx.size() >= 4){
        ans = max(ans, vx[0] + vx[1] + vx[2] + vx[3] + 1);
    }
    if(vx.size() >= 3){
        dp[u] = vx[0] + vx[1] + vx[2] + 1;
        if(p != 0) ans = max(ans, vx[0] + vx[1] + vx[2] + 2);
    }else dp[u] = 1;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << "\n";
}
