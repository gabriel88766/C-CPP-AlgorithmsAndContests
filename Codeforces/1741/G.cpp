#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e4+3;
int d[7][N];
vector<int> adj[N];
int n;

void bfs(int src, int p){
    for(int i=1;i<=n;i++) d[p][i] = INF_INT;
    queue<int> q;
    q.push(src); 
    d[p][src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[p][u] + 1 < d[p][v]){
                d[p][v] = d[p][u] + 1;
                q.push(v);
            }
        }
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
        int m;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int f, k;
        cin >> f;
        vector<int> friends(f+1);
        for(int i=1;i<=f;i++) cin >> friends[i];
        cin >> k;
        vector<int> indx(k);
        for(int i=0;i<k;i++){
             cin >> indx[i];
             bfs(friends[indx[i]], i);
        }
        bfs(1, k);


        vector<vector<int>> pos(f+1);

        vector<vector<ll>> dp(k+1, vector<ll> (1 << k, INF_LL));
        for(int i=0;i<k;i++) dp[i][1 << i] = d[k][friends[indx[i]]];
        for(int i=1;i < (1 << k); i++){
            for(int j=0;j<k;j++){
                if(i & (1 << j)){
                    for(int w = 0; w < k; w++){
                        if(i & (1 << w) && w != j){
                            dp[j][i] = min(dp[j][i], dp[w][i ^ (1 << j)] + d[w][friends[indx[j]]]);
                        }
                    }
                }
            }
        }

        
        for(int i=1;i<=f;i++){
            bool cont = false;
            for(int j=0;j<k;j++) if(indx[j] == i) cont = true; //no car
            if(cont) continue;
            //has car
            int x = friends[i];
            for(int u=1;u< (1 << k); u++){
                for(int v=0;v<k;v++){
                    if(dp[v][u] + d[v][x] == d[k][x]){
                        pos[i].push_back(u);
                    }
                }
            }
        }

        vector<bool> ans(1 << k, false);
        ans[0] = true;
        for(int i = 1;i<=f;i++){
            bool cont = false;
            for(int j=0;j<k;j++) if(indx[j] == i) cont = true; //no car
            if(cont) continue;
            //has car
            vector<bool> aux(1 << k, false);
            for(int j=0;j<pos[i].size();j++){
                for(int w = 0;w < (1<<k);w++){
                    if(ans[w]) aux[w | pos[i][j]] = true;
                }
            }
            for(int w = 0;w < (1<<k);w++) if(ans[w]) aux[w] = true;
            ans = aux;
        }
        int ansv = k;
        for(int w=0; w < (1 << k); w++) if(ans[w]) ansv = min(ansv, k-__builtin_popcount(w));
        cout << ansv << "\n";
    

        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
