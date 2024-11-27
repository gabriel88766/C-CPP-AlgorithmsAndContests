#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
ll dp[N][2]; // 0 = at least 1 is free. 1 = maybe none.
int mx[N];
vector<pair<int,int>> adj[N];
void dfs(int u, int p){
    ll sum = 0;
    vector<ll> vb;
    for(auto [v, w] : adj[u]){
        if(v != p){
            dfs(v, u);
            sum += dp[v][1];
            //opt1 : sum v,0 and w
            //opt2 : sum v,1
            vb.push_back(dp[v][0] - dp[v][1] + w);
        }
    }
    sort(vb.begin(), vb.end(), greater<ll>());
    int qs = 0;
    if(mx[u] == 0){
        dp[u][0] = -INF_LL;
        dp[u][1] = sum;
    }else if(mx[u] <= vb.size()){
        if(mx[u] == 1) dp[u][0] = sum;
        for(int i=0;i<mx[u];i++){
            if(vb[i] > 0) sum += vb[i];
            if(i == mx[u] - 2) dp[u][0] = sum;
            if(i == mx[u] - 1) dp[u][1] = sum;
        }
    }else{
        for(int i=0;i<vb.size();i++){
            if(vb[i] > 0) sum += vb[i];
        }
        dp[u][0] = dp[u][1] = sum;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> mx[i];
    for(int i=1;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(1, 0);
    cout << dp[1][1] << "\n";
}
