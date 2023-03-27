#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int sz[N], pos[N], inor[N];
int cnt = 0;

void dfs(int u = 1){
    inor[++cnt] = u;
    pos[u] = cnt;
    sz[u] += 1;
    for(auto v: adj[u]){
        dfs(v);
        sz[u] += sz[v];
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs();
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        if(b > sz[a]) cout << "-1\n";
        else cout << inor[pos[a]+b-1] << "\n";
    }
}
