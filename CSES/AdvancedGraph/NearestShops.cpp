#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
pair<int, int> d[2][N];
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> src(k);
    for(int i=0;i<k;i++) cin >> src[i];
    queue<pair<int, int>> q;
    for(int i=0;i<2;i++){
        for(int j=1;j<=n;j++){
            d[i][j] = {INF_INT, INF_INT};
        }
    }
    // memset(d, 63, sizeof(d));
    for(auto &x : src){
        q.push({x, 0}); //vertex, 0 or 1
        d[0][x] = {0, x};
    }
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while(!q.empty()){
        auto [u, j] = q.front();
        q.pop();
        for(auto v : adj[u]){
            pair<int, int> curd = {d[j][u].first + 1, d[j][u].second};
            assert(v >= 0 && v < N);
            if(curd.first + 1 < d[0][v].first){
                d[0][v] = curd;
                q.push({v, 0});
            }else if(curd.first + 1 < d[1][v].first && d[0][v].second != curd.second){
                d[1][v] = curd;
                q.push({v, 1});
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(d[0][i].first != INF_INT && d[0][i].second != i) ans[i] = d[0][i].first;
        else if(d[1][i].first != INF_INT) ans[i] = d[1][i].first;
        else ans[i] = -1;
        cout << ans[i] << " ";
    }
    cout << "\n";
}
