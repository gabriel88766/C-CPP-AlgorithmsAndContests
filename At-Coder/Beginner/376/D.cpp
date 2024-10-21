#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(d, 63, sizeof(d));
    d[1] = 0;
    queue<int> q;
    q.push(1);
    int ans = INF_INT;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        bool ok = false;
        for(auto v : adj[u]){
            if(v == 1){
                ans = d[u] + 1;
                ok = true;
                break;
            }
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        if(ok) break;
    }
    if(ans == INF_INT) cout << "-1\n";
    else cout << ans << "\n";
}
 