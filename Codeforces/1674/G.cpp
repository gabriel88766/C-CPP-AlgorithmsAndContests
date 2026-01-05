#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int indg[N], outdg[N];
int dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indg[b]++;
    }
    vector<int> ord;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indg[i] == 0) q.push(i);
    }
    while(q.size()){
        auto u = q.front();
        q.pop();
        ord.push_back(u);
        for(auto v : adj[u]){
            indg[v]--;
            if(indg[v] == 0) q.push(v);
        }
    }
    reverse(ord.begin(), ord.end());
    for(int i=1;i<=n;i++){
        for(auto v : adj[i]){
            outdg[i]++;
            indg[v]++;
        }
    }
    int ans = 0;
    for(auto x : ord){
        for(auto v : adj[x]){
            if(indg[v] > 1 && outdg[x] > 1) dp[x] = max(dp[x], dp[v]);
        }
        dp[x] += 1;
        ans = max(ans, dp[x]);
    }
    cout << ans << "\n";

}
