#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
vector<int> ans;
int vis[N];
//I can assume there is no cycle
void dfs(int u){
    for(auto &v : adj[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
        }
    }
    if(u != 1)ans.push_back(u);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        for(int j=0;j<x;j++){
            int k;
            cin >> k;
            adj[i].push_back(k);
        }
    }
    dfs(1);
    for(auto &x : ans) cout << x << " ";
    cout << "\n";
}
