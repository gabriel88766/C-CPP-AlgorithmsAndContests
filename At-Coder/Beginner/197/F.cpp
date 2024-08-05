#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> adj[1001];
vector<char> adjl[1001];
int d[1001][1001];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    queue<pair<int,int>> q;
    q.push({1, n});
    for(int i=0;i<m;i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adjl[a].push_back(c);
        adjl[b].push_back(c);
    }
    memset(d, 63, sizeof(d));
    d[1][n] = 0;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++){
            for(int j=0;j<adj[y].size();j++){
                //even palindromes
                if(adjl[x][i] == adjl[y][j]){
                    int v1 = adj[x][i];
                    int v2 = adj[y][j];
                    if(v1 > v2) swap(v1, v2);
                    if(d[v1][v2] > d[x][y] + 2){
                        d[v1][v2] = d[x][y] + 2;
                        q.push({v1, v2});
                    }
                }
                //odd palindromes
                if(adj[x][i] == y){
                    d[y][y] = min(d[y][y], d[x][y] + 1);
                }
                if(adj[y][j] == x){
                    d[x][x] = min(d[x][x], d[x][y] + 1);
                }
            }
        }
    }
    int ans = INF_INT;
    for(int i=1;i<=n;i++) ans = min(ans, d[i][i]);
    if(ans == INF_INT) cout << "-1\n";
    else cout << ans << "\n";
}   
