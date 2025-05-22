#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2505;
vector<int> adj[N];
int d[N][N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(d, 63, sizeof(d));
    for(int i=1;i<=n;i++){
        queue<pair<int, int>> q;
        q.push({i, 0});
        d[i][i][0] = 0;
        while(!q.empty()){
            auto [u, j] = q.front();
            q.pop();
            for(auto &v : adj[u]){
                if(d[i][v][j^1] > d[i][u][j] + 1){
                    d[i][v][j^1] = d[i][u][j] + 1;
                    q.push({v, j^1});
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        int a, b, x;
        cin >> a >> b >> x;
        if(d[a][b][x%2] <= x) cout << "YES\n";
        else cout << "NO\n";
    }
}   
