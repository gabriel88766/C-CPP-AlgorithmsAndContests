#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<pair<int, int>> adj[N];
int qnt[N][2];
int d[N];
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
        for(int i=1;i<=n;i++){
            d[i] = INF_INT;
        }
        for(int i=1;i<=m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
            qnt[a][c]++;
            qnt[b][c]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(qnt[i][0] == 0 || qnt[i][1] == 0){
                q.push(i);
                d[i] = 0;
            }
        }
        vector<bool> rem(n+1, false);
        while(q.size()){
            auto u = q.front();
            rem[u] = true;
            q.pop();
            for(auto [v, c] : adj[u]){
                if(rem[v]) continue;
                qnt[v][c]--;
                qnt[u][c]--;
                if(qnt[v][0] == 0 || qnt[v][1] == 0){
                    if(d[v] == INF_INT){
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
        }



        if(d[1] == INF_INT) cout << "-1\n";
        else cout << d[1]+1 << "\n";



        for(int i=1;i<=n;i++){
            adj[i].clear();
            qnt[i][0] = qnt[i][1] = 0;
        }
    }
}
