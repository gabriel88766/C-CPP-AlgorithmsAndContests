#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
bool dp[N][3];

void dfs(int u, int p){
    int cnt = 0, x0 = 0, x2 = 0;
    dp[u][1] = true; //always true
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            cnt++;
            if(dp[v][0]) x0++;
            if(dp[v][2]) x2++;
        }
    }
    if(cnt != 0){ // go for the children!
        cnt %= 3;
        dp[u][cnt] = true;
        if(x0 == 1) dp[u][(cnt+2)%3] = true;
        if(x0 >= 2) dp[u][0] = dp[u][2] = true; //all true
        if(x2 == 1) dp[u][(cnt+1)%3] = true;
        if(x2 >= 2) dp[u][0] = dp[u][2] = true; //all true
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
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        if(dp[1][0]) cout << "YES\n";
        else cout << "NO\n";
        //reset
        for(int i=1;i<=n;i++){
            adj[i].clear();
            dp[i][0] = dp[i][1] = dp[i][2] = false;
        }
    }
}
