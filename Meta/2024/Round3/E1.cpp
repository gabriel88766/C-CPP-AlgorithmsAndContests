#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 300005;
map<int, int> dist[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("all_triplets_shortest_path_part_1_input.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            dist[a][b] = dist[b][a] = 1;
            dist[i][i] = 1;
        }
        dist[n][n] = 1;
        bool ok = true;
        for(int k=1;k<=n;k++){
            if(dist[1][k]){
                for(auto v: adj[k]){
                    dist[1][v] = 1;
                }
            }
        }
        for(int i=1;i<=n;i++) if(!dist[1].count(i)) ok = false;
        if(ok){
            for(int u=2;u<=n;u++){
                bool cok = false;
                for(auto v : adj[u]){
                    if(v < u || dist[v].count(1)) cok = true;
                }
                if(!cok) ok = false;
                else dist[u][1] = true;
            }
        }
        cout << "Case #" << i << ": ";
        if(ok) cout << "Lucky\n";
        else cout << "Wrong\n";

        for(int i=1;i<=n;i++){
            dist[i].clear();
        }

    }
}
