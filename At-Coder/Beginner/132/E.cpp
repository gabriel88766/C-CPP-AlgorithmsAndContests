#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int d[N][3];
vector<int> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    queue<pair<int, int>> q;
    q.push({s, 0});
    memset(d, 63, sizeof(d));
    d[s][0] = 0;
    while(q.size()){
        auto [u, x] = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[v][(x+1)%3] > d[u][x] + 1){
                d[v][(x+1)%3] = d[u][x] + 1;
                q.push({v, (x+1) % 3});
            }
        }
    }
    if(d[t][0] < INF_INT) cout << d[t][0]/3 << "\n";
    else cout << "-1\n";
}
