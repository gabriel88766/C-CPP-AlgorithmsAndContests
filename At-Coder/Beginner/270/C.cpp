#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> adj[200005];
int x, y;
vector<int> ans;
void dfs(int u, int p){
    ans.push_back(u);
    if(u == y){
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
    for(auto v : adj[u]){
        if(v != p) dfs(v, u);
    }
    ans.pop_back();
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n >> x >> y;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(x, 0);
}
