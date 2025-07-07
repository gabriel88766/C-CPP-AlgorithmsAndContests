#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int c[N];
vector<int> adj[N];
int cnt[N];
bool ok[N];
void dfs(int u, int p){
    cnt[c[u]] += 1;
    if(cnt[c[u]] == 1) ok[u] = true;
    for(auto v : adj[u]){
        if(v != p) dfs(v, u);
    }
    cnt[c[u]] -= 1;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++){
        if(ok[i]) cout << i << "\n";
    }
}
