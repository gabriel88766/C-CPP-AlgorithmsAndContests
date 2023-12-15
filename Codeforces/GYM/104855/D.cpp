#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        vector<vector<int>> adjc(n+1);
        for(int i=0;i<m;i++){
            int a, b, cl;
            cin >> a >> b >> cl;
            adj[a].push_back(b);
            adjc[a].push_back(cl);
        }
        vector<vector<int>> vis(n+1);
        vis[1].push_back(0);
        queue<pair<int,int>> qp;
        qp.push({1, 0});
        while(!qp.empty()){
            auto [u, c] = qp.front();
            qp.pop();
            for(int i=0;i<adj[u].size();i++){
                if(adjc[u][i] == c) continue;
                auto v = adj[u][i];
                if(vis[v].size() == 0){
                    vis[v].push_back(adjc[u][i]);
                    qp.push({v, adjc[u][i]});
                }else if(vis[v].size() == 1 && vis[v].back() != adjc[u][i]){
                    vis[v].push_back(adjc[u][i]);
                    qp.push({v, adjc[u][i]});
                }
            }
        }
        for(int i=1;i<=n;i++) if(vis[i].size()) cout << i << " ";
        cout << "\n";
    }
}
