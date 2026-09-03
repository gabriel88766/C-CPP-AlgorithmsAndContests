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
        int n, q;
        cin >> n >> q;
        vector<vector<int>> adj(n+1);
        adj[0].push_back(1);
        for(int i=1;i<=n;i++){
            int a, b;
            cin >> a >> b;
            if(a != 0){
                adj[i].push_back(a);
                adj[i].push_back(b);
            }
        }
        vector<int> sub(n+1);
        vector<int> ord;
        vector<int> fs(n+1);
        vector<vector<ll>> sum(n+1, vector<ll>(21));
        vector<vector<int>> anc(n+1, vector<int>(21));
        function<void(int,int)> dfs = [&](int u, int p){
            fs[u] = ord.size();
            ord.push_back(u);
            sub[u] = 1;
            if(adj[u].size()){
                dfs(adj[u][0], u);
                ord.push_back(u);
                if(adj[u].size() == 2){
                    dfs(adj[u][1], u);
                    ord.push_back(u);
                    sub[u] += sub[adj[u][0]] + sub[adj[u][1]];
                }else{
                    sub[u] += sub[adj[u][0]];
                }
            }
            sum[u][0] = 2 * sub[u] - 2;
            anc[u][0] = p;
        };
        dfs(0, 0);
        for(int i=1;i<=20;i++){
            for(int j=0;j<=n;j++){
                anc[j][i] = anc[anc[j][i-1]][i-1];
                sum[j][i] = sum[j][i-1] + sum[anc[j][i-1]][i-1];
            }
        }
        for(int i=1;i<=q;i++){
            int v, k;
            cin >> v >> k;
            for(int j=20;j>=0;j--){
                if(sum[v][j] + (1 << j) <= k){
                    k -= sum[v][j] + (1 << j);
                    v = anc[v][j];
                }
            }
            cout << ord[fs[v] + k] << " ";
        }
        cout << "\n";
    }
}
