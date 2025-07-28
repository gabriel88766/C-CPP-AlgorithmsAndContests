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
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<vector<short>> md(n+1);
        for(int i=1;i<=n;i++){
            md[i].resize(3*n+1, 30000);
        }

        queue<pair<int, int>> q;
        q.push({1, 0});
        md[1][0] = 0;
        while(q.size()){
            auto [u, d] = q.front();
            if(u == n) break;
            assert(d <= 3*n);
            q.pop();
            int w = md[u][d];
            int j = d % adj[u].size();
            if(md[adj[u][j]][d+1] > w){
                md[adj[u][j]][d+1] = w;
                q.push({adj[u][j], d+1});
            }
            if(md[u][d+1] > w+1){
                md[u][d+1] = w+1;
                q.push({u, d+1});
            }
            
        }
        int d = INF_INT;
        for(int i=0;i<=3*n;i++){
            if(md[n][i] != 30000){
                d = i;
                break;
            }
        }
        cout << d << " " << md[n][d] << "\n";
        
    }
}