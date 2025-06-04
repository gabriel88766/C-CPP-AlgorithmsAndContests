#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
bool sw[N];
vector<int> adj[2][N];
int d[2][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[c][a].push_back(b);
        adj[c][b].push_back(a);
    }
    for(int i=1;i<=k;i++){
        int x;
        cin >> x;
        sw[x] = true;
    }
    memset(d, 63, sizeof(d));
    d[1][1] = 0;
    deque<pair<int, int>> q;
    q.push_back({1, 1});
    while(!q.empty()){
        auto [u, t] = q.front();
        q.pop_front();
        if(sw[u] && d[t^1][u] > d[t][u]){
            d[t^1][u] = d[t][u];
            q.push_front({u, t^1});
        }
        for(auto &v : adj[t][u]){
            if(d[t][v] > d[t][u] + 1){
                d[t][v] = d[t][u] + 1;
                q.push_back({v, t});
            }
        }
    }
    if(d[1][n] != INF_INT || d[0][n] != INF_INT) cout << min(d[0][n], d[1][n]) << "\n";
    else cout << "-1\n";
}
