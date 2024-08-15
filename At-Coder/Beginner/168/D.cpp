#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
vector<int> adj[N];
int ans[N];
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
        adj[b].push_back(a);
    }
    cout << "Yes\n";
    queue<int> q;
    q.push(1);
    memset(d, 63, sizeof(d));
    d[1] = 0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(d[v] > d[u] + 1){
                ans[v] = u;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    for(int i=2;i<=n;i++) cout << ans[i] << "\n";
}
