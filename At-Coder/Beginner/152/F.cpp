#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<pair<int, int>> adj[60];
vector<int> cond[60];
ll dp[2][1 << 20];
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
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        //bad but ok;
        int a, b;
        cin >> a >> b;
        vector<int> d(n+1, INF_INT);
        vector<pair<int, int>> par(n+1);
        d[a] = 0;
        queue<int> q;
        q.push(a);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto &[v, j] : adj[u]){
                if(d[v] > d[u] + 1){
                    d[v] = d[u] + 1;
                    q.push(v);
                    par[v] = {u, j};
                }
            }
        }
        vector<int> edg;
        while(b != a){
            edg.push_back(par[b].second);
            b = par[b].first;
        }
        for(auto &x : edg) cond[x].push_back(i);
    }
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        int cm = 0;
        int b = i & 1;
        for(auto &x : cond[i]) cm |= (1 << x);
        // cout << cm << "\n";
        for(int j=0;j<(1 << m);j++){
            dp[b][j] = 0;
        }
        for(int j=0;j<(1 << m);j++){
            dp[b][j] += dp[b^1][j]; // white
            dp[b][j | cm] += dp[b^1][j]; //black
        }
    }   
    cout << dp[(n-1)&1][(1 << m)-1] << "\n";
}
